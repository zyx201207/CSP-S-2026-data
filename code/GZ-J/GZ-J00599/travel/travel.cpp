//GZ-J00599 贵阳市白云区第二高级中学 王良楷锋
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string r1,r2,x1,x2;

bool b(char a,char b){
	if ((a == 'A' && b == 'B') ||(a == 'B' && b == 'A')) return true;
	else if ((a == 'B' && b == 'C') ||(a == 'C' && b == 'B')) return true;
	else if ((a == 'D' && b == 'F') ||(a == 'F' && b == 'D')) return true;
	else return false;
}
int main(){
	ifstream fin("travel.in",ios::in);
	ofstream fout("travel.out",ios::out);
	
	fin >> r1 >> r2 >> x1 >> x2;
	
	if (r1 == x1) fout << 1;//同一车厢
	else {
		fout << "0000";	
		return 0;
	}
	
	if (r2.substr(0,2) == x2.substr(0,2)) fout << 1;//同一车厢同一排
	else {
		fout << "000";
		return 0;
	}
	
	
	if(((r2[2] >='A' && r2[2] <='C') && (x2[2] >='A' && x2[2] <='C')) || ((r2[2] >='D' && r2[2] <='F') && (x2[2] >='D' && x2[2] <='F'))) fout << 1;
	else {
		fout << "00";
		return 0;
	}
	
	if (b(r2[2],x2[2])){
		fout << 1;
	}
	else fout << 0;
	return 0;
	
	
}
	 