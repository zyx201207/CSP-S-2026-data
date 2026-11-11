#include<bits/stdc++.h>

using namespace std;

string s1,s2,s3,s4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	bool f=(s2[0]==s4[0]&&s2[1]==s4[1]);
	bool f1=0,f2=0,f3=0,f4=0;
	char ch1=s2[2],ch2=s4[2];
	if(s1==s3) f1=1;
	if(f&&f1) f2=1;
	if(((ch1<'D'&&ch2<'D')||(ch1>='D'&&ch2>='D'))&&f2) f3=1;
	if(((ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D')||(abs(ch1-ch2)==1))&&f3) f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
