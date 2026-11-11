#include<iostream>
#include<string>
#include <algorithm>
#include <cstdio>
using namespace std;
bool check(char c){
	return c=='D'||c=='F';
}
bool is(char a,char b){
	if((a=='D'&&b=='C')||(a=='C'&&b=='D'))return false;
	else return abs((int)a-(int)b)==1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int pc1=stoi(s1.substr(0,2)),pc2=stoi(s2.substr(0,2));
	char z1=s1[2],z2=s2[2];
	bool f1=false,f2=false;//false=left,true=right
	f1=check(z1);
	f2=check(z2);
	cout<<(c1==c2);
	cout<<(c1==c2&&pc1==pc2);
	cout<<(c1==c2&&pc1==pc2&&f1==f2);
	cout<<(c1==c2&&pc1==pc2&&f1==f2&&is(z1,z2));
	return 0;
} 
