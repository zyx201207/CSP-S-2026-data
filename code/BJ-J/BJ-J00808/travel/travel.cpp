#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	cin>>c1>>s1>>c2>>s2;
	bool f=0;
	if (c1==c2) {
		cout<<"1";
	} else {
		cout<<"0";
		f=1;
	}
	int a=0,b=0;
	for (int i=0;i<=1;i++) {
		a=a*10+s1[i];
	}
	for (int i=0;i<=1;i++) {
		b=b*10+s2[i];
	}
	if (a==b and f==0) {
		cout<<"1";
	} else {
		cout<<"0";
		f=1;
	}
	char x,y;
	x=s1[2];
	y=s2[2];
	if (a==b and x>='A' and x<='C' and y>='A' and y<='C' and f==0) {
		cout<<"1";
	} else if (a==b and x>='D' and x<='F' and y>='D' and y<='F' and f==0) {
		cout<<"1";
	} else {
		cout<<"0";
		f=1;
	}
	if (a==b and int(x)+1==int(y) and f==0) {
		cout<<"1";
	} else if (a==b and int(y)+1==int(x) and f==0) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	return 0;
}
