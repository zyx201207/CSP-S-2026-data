#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int ta,tb;
string sa,sb;
string la,lb;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>ta>>sa>>tb>>sb;
	if(ta==tb) {
		cout<<1;
		la=sa[0]+sa[1];
		lb=sb[0]+sb[1];
		if(la==lb) {
			cout<<1;
			if((sa[2]<='C'&&sb[2]<='C')||(sa[2]>='D'&&sb[2]>='C')) {
				cout<<1;
				if(abs(sa[2]-sb[2])==1) {
					cout<<1;
				} else cout<<0;
			} else cout<<"00";
		} else cout<<"000";
	} else cout<<"0000";
	return 0;
}
