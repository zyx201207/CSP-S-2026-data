#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx!=cy) {
		cout<<0<<0<<0<<0;
		return 0;
	} else {
		cout<<1;
		if(sx[1]==sy[1]&&sy[0]==sx[0]) {
			cout<<1;
			if((sx[2]<='C'&&sy[2]<='C')||(sx[2]>'C'&&sy[2]>'C')) {
				cout<<1;
				if(abs(sx[2]-sy[2])==1) cout<<1;
				else cout<<0;
			} else cout<<0<<0;
		} else cout<<0<<0<<0;
	}
	return 0;
}
