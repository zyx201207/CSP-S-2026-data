#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool check1(string a,string b){
	if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C')return 1;
	if(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F')return 1;
	return 0;
}
bool check2(string a,string b){
	if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='A')return 1;
	if(a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B')return 1;
	if(a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>s1>>s2>>s3>>s4;
	int f1=0,f2=0,f3=0,f4=0;
	if(s1==s3)f1=1;
	if(f1==0){
		f2=0,f3=0,f4=0;
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1])f2=1;
	if(f2==0){
		f3=0,f4=0;
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}
	if(check1(s2,s4))f3=1;
	if(f3==0){
		f4=0;
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}
	if(check2(s2,s4))f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
