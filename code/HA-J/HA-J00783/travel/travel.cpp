#include<bits/stdc++.h>
using namespace std;
string ds,ds1,dds,dds1,a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ds>>ds1>>dds>>dds1;
	if(ds==dds) {
		cout<<"1";
		for(int i=0; i<=1; i++) {
			a[i]=ds1[i];
			b[i]=dds1[i];
		}
		if(a==b) {
			cout<<"1";
		}
		if(ds1[2]>='A'&&ds1[2]<='C') {
			if(dds1[2]>='A'&&dds1[2]<='C') {
				cout<<"1";
			}
		} else {
			if(dds1[2]>='D'&&dds1[2]<='F') {
				cout<<"1";
			}
		}
		if(ds1[2]=='A'&&dds1[2]=='B') {
			cout<<"1";
		} else if(ds1[2]=='B') {
			if(dds1[2]=='A'||dds1[2]=='C') {
				cout<<"1";
			} else {
				cout<<"0";
			}
		} else if(ds1[2]=='C') {
			if(dds1[2]=='B') {
				cout<<"1";
			} else {
				cout<<"0";
			}
		} else if(ds1[2]=='D') {
			if(dds1[2]=='E') {
				cout<<"1";
			} else {
				cout<<"0";
			}
		} else if(ds1[2]=='E') {
			if(dds1[2]=='D') {
				cout<<"1";
			} else {
				cout<<"0";
			}
		} else {
			cout<<"0";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
