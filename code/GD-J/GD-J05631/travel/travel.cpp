#include<bits/stdc++.h>
#define intt long long
using namespace std;
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	intt c1,c2;string s1,s2;
	fin>>c1>>s1>>c2>>s2;
	intt ss1,ss2;
	ss1=(s1[0]-'0')*10+(s1[1]-'0');
	ss2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		fout<<1;
		if(ss1==ss2){
			fout<<1;
			if((s1[2]=='A'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B'))
				fout<<1<<1;//
			else if((s1[2]=='C'||s1[2]=='D'||s1[2]=='F')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='F')){
				fout<<1;//
				if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))
					fout<<1;  //
				else fout<<0;//
			}
			else
				fout<<0<<0;//
		}
		else fout<<0<<0<<0;
	}
	else fout<<0<<0<<0<<0;
	return 0;
}
/*

*/ 
