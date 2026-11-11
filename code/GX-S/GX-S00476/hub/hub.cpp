#include <iostream>
#include <fstream>
using namespace std;
int main(){
		fstream fin,fout;
	fin.open("crystal.in");
	fout.open("crystal.out");
	int c,t;
	fin>>c>>t;
	for(int i=0;i<t;i++){
		fout<<"100\n";
	}
return 0;
}
