#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	int c1,c2,l1,l2;
	bool ans[4];
	char k1,k2;
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	string s1,s2;
	fin >> c1 >> s1 >> c2 >> s2;
	l1=s1[0]*10+s1[1];
	l2=s2[0]*10+s2[1];
	k1=s1[2];k2=s2[2];
	ans[0]=(c1==c2);
	fout << (ans[0] ?'1':'0');
	ans[1]=ans[0]&&(l1==l2);
	fout << (ans[1]?'1':'0');
	ans[2]=ans[1]&&(
		(k1<='C'&&k2<='C') || 
		(k1>='D'&&k2>='D')
	);
	fout << (ans[2] ?'1':'0');
	ans[3]=ans[2]&&(k1-k2==1 || k2-k1==1);
	fout << (ans[3] ?'1':'0');
	fin.close();
	fout.close();
	return 0;
} 
