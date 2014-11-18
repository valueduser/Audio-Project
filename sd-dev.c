/* Read files from an SD card into the files array */
#include <SD.h>

// char *files[3]={"sample1.mp3", "sample2.mp3", "sample3.mp3"};
int fileCount = 0;

void countFiles(File dir) {
	Serial.println("Counting files...")
	while(true) {
		File file =  dir.openNextFile();
		if (! file) {
			// no more files
			Serial.println("Out of files.");
		   break;
		}
	}
	if (file.isDirectory()) {
	 	//do nothing
	} else {
		fileCount++;
		Serial.print(fileCount);
	}
	file.close();
}

char *files[fileCount];

void getFiles(File dir) {
	int i = 0;
	while(true) {
		File file =  dir.openNextFile();
		if (! file) {
			// no more files
			Serial.println("Out of files.");
		   break;
		}
	}
	if (file.isDirectory()) {
	 	//do nothing
	} else {
		i++;
		fileCount++;
		Serial.print(file.name());
		*files[i] = file.name();
	}
	file.close();
}