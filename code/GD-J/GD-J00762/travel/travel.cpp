#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2,s1,s2;
char ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1) {
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	s1=a2[0]+a2[1];
	s2=b2[0]+b2[1];
	if(s1!=s2) {
		cout<<"000";
		return 0;
	}
	cout<<"1";
	ss1=a2[2];
	ss2=b2[2];
	if(ss1<='C'&&ss2>'C'||ss1>'C'&&ss2<='C') {
		cout<<"00";
		return 0;
	}
	cout<<"1";
	int a,b;
	a=ss1-'A';
	b=ss2-'A';
	if(ss1=='D'&&ss2=='F'||ss1=='F'&&ss2=='D') {
		cout<<"1";
		return 0;
	}
	if(abs(a-b)>1) {
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}

