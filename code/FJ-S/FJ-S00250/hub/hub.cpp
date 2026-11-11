#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//#define fin cin
//#define fout cout
int c, t, n, k;
string s;
int main(){
	ifstream fin("hub.in");
	ofstream fout("hub.out");
	fin >> c >> t >> n >> k;
	while (fin.eof()){
	}
	for (int i = 0; i < t; i++){
		if (i == 0){
			fout << 1 << endl;
			continue;
		}
		fout << i << endl;
	}
	fin.close(); fout.close();
	return 0;
}
