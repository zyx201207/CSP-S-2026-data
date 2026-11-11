#include<bits/stdc++.h>//CCF=Chinese Can Fly!		(Œﬁ∂Ò“‚)
using namespace std;
bool near(const char a,const char b){
	if(abs(a-b)==1&&!((a=='C'&&b=='D')||(a=='D'&&b=='C')))
		return true;
	if(a=='D'&&b=='F'||a=='F'&&b=='D')
		return true;
	return false;
}
bool side(const char a,const char b){
	if(a<='C'&&b<='C'||a>='D'&&b>='D')
		return true;
	return false;
}
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	char s1,s2;
	int a,b,c,d;
	fin>>a>>b>>s1>>c>>d>>s2;
	bool tmp;
	fout<<(tmp=a==c)<<(tmp=(tmp&&b==d))<<(tmp=(tmp&&side(s1,s2)))<<(tmp&&near(s1,s2));
	fin.close();
	fout.close();
	return 0;
}
