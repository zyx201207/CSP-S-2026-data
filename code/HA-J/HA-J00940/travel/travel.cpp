#include<bits/stdc++.h>
using namespace std;
bool pd(string a,string b) {
	if(a[2]>='A'&&a[2]<='C') {
		if(b[2]>='A'&&b[2]<='C') {
			return 1;
		} else {
			return 0;
		}
	} else if(a[2]=='F'||a[2]=='D') {
		if(b[2]=='F'||b[2]=='D') {
			return 1;
		} else {
			return 0;
		}
	}
	return 0;
}
bool pd2(string a,string b,int f) {
	if(f==3) {
		if(a[2]+1==b[2]||b[2]==a[2]-1) {
			return 1;
		}
	} else {
		return 0;
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int f1=123;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
		f1=1;
	} else {
		cout<<0;
	}
	if(f1==1&&s1[0]==s2[0]&&s1[1]==s2[1]) {
		cout<<1;
		f1=2;
	} else {
		cout<<0;
	}
	if(f1==2&&pd(s1,s2)) {
		cout<<1;
		f1=3;
	} else {
		cout<<0;
	}
	cout<<pd2(s1,s2,f1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
