#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//#define fin cin
//#define fout cout
string c1, c2, c3, c4;
bool flag = 0;
bool check(string a, string b){
	if (a[2] == 'A' || a[2] == 'B' || a[2] == 'C'){
		if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C') return 1;
		else return 0;
	}
	else {
		if (b[2] == 'D' || b[2] == 'F') return 1;
		else return 0;
	}
}
bool check2(string a, string b){
	if (a[2] == 'A'){
		if (b[2] == 'B') return 1;
	}
	else if (a[2] == 'B'){
		if (b[2] == 'A' || b[2] == 'C') return 1;
	}
	else if (a[2] == 'C'){
		if (b[2] == 'B') return 1;
	}
	else if (a[2] == 'D'){
		if (b[2] == 'F') return 1;
	}
	else if (a[2] == 'F'){
		if (b[2] == 'D') return 1;
	}
	return 0;
}
int main(){
	fstream fin("travel.in");
	fstream fout("travel.out");
	fin >> c1 >> c2 >> c3 >> c4;
	// 1判断是否在同一节车厢 
	if (c1 == c3) fout << '1';
	else {
		fout << '0';
		flag = 1;
	}
	// 2判断同排
	if (!flag){
		if (c2[0] == c4[0] && c2[1] == c4[1]) fout << '1';
		else {
		fout << '0';
		flag = 1;
		}
	}
	else cout << '0';
	//3判断同侧 
	if (flag){
		fout << '0';
	}
	else {
		if (check(c2, c4)) fout << '1';
		else fout << '0';
	}
	// 4判断相邻
	if (!flag){
		if (check2(c2, c4)) fout << '1';
		else fout << '0';
	}
	else fout << '0';
	fin.close(); fout.close();
	return 0;
}
