#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int D=1e6+10;
struct t {
	string cx;
	string zw;
};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	t R,X;
	cin>>R.cx>>R.zw>>X.cx>>X.zw;
	if(R.cx==X.cx) {
		cout<<1;
		if((R.zw[0]==X.zw[0] )&&( R.zw[1]==X.zw[1])) {
			cout<<1;
			if((R.zw[2]=='C' && X.zw[2]=='D') || (R.zw[2]=='D' && X.zw[2]=='C')) {
				cout<<0<<0;
			} else {
				cout<<1;
				char r=R.zw[2];
				char x=X.zw[2];
				if(r+1!=x || r-1!=x) {
					cout<<0;
				} else {
					cout<<1;
				}
			}
		} else {
			cout<<0<<0<<0;
		}
	} else {
		cout<<0<<0<<0<<0;
	}
	return 0;
}
