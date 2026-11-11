#include <bits/stdc++.h>
using namespace std;
string c,c1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b) {
		cout<<1;
		c+=a1[0],c1+=b1[0];
		c+=a1[1],c1+=b1[1];
		if(c==c1) {
			cout<<1;
			if(a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C') {
				cout<<1;
				int v=a1[2];
				int y=b1[2];
				if(abs(v-y)==1) {
					cout<<1;
				} else {
					cout<<0;
				}
			} else if(a1[2]>='D'&&a1[2]<='F'&&b1[2]>='D'&&b1[2]<='F') {
				cout<<1;
				int v=a1[2];
				int y=b1[2];
				if(abs(v-y)==1) {
					cout<<1;
				} else {
					cout<<0;
				}
			} else {
				cout<<0<<0;
			}
		} else {
			cout<<0<<0<<0;
		}
	} else {
		cout<<0<<0<<0<<0;
	}
	return 0;
}
