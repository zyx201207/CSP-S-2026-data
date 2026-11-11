#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pd(char x1,char x2) {
	int a=0,b=0;
	if(x1=='A'||x1=='B'||x1=='C') {
		a=0;
	} else {
		a=1;
	}
	if(x2=='A'||x2=='B'||x2=='C') {
		b=0;
	} else {
		b=1;
	}
	if(a==b) {
		return true;
	} else {
		return false;
	}
}
bool pds(char y1,char y2) {
	bool flag=false;
	if(y1>='A'&&y1<='C'&&y2>='A'&&y2<='C') {
		int tmp1=y1-'A';
		int tmp2=y2-'A';
		int tmp3=abs(tmp1-tmp2);
		if(tmp3==1) {
			flag=true;
		}
	} else if(y1>='D'&&y1<='F'&&y2>='D'&&y2<='F') {
		int tmp1=y1-'A';
		int tmp2=y2-'A';
		int tmp3=abs(tmp1-tmp2);
		if(tmp3==1) {
			flag=true;
		}
	}
	if(flag==true) {
		return true;
	} else {
		return false;
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&
	        pd(s1[2],s2[2])==true) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&pd(s1[2],s2[2])==true&&pds(s1[2],s2[2])==true) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	return 0;
}
