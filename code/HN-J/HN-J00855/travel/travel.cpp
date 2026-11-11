#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1,s2,s3,s4; 
bool flag1,flag2,flag3,flag4;
bool Check1(){
	char c=s2[2];
	char d=s4[2];
	if(c<='C'&&d<='C') return 1;
	if(c>='D'&&d>='D') return 1;
	return 0; 
}
bool Check2(){
	char c=s2[2];
	char d=s4[2];
	return c==d+1||d==c+1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	flag1=(s1==s3);
	string sa=s2.substr(0,2);
	string sb=s4.substr(0,2);
	flag2=(sa==sb&&flag1);
	flag3=(flag2&&Check1());
	flag4=(flag3&&Check2());
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}

