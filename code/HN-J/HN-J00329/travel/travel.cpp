#include <bits/stdc++.h>
using namespace std;
string r,rr,x,xx;
bool a[5];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rr>>x>>xx;
	//cout<<r<<' '<<rr<<' '<<x<<' '<<xx<<'\n';
	if(r==x) {
		a[1]=1;
		if(rr[0]==xx[0]&&rr[1]==xx[1]) {
			a[2]=1;
			if((rr[2]>='A'&&rr[2]<='C'&&xx[2]>='A'&&xx[2]<='C')||(rr[2]>='D'&&rr[2]<='F'&&xx[2]>='D'&&xx[2]<='F')) {
				a[3]=1;
				if( (abs(rr[2]-xx[2])==1)&& !((rr[2]=='C'&&xx[2]=='D')||(rr[2]=='D'&&xx[2]=='C')) && !((rr[2]=='A'&&xx[2]=='C')||(rr[2]=='C'&&xx[2]=='A'))) {
					a[4]=1;
				} else {
					a[4]=0;
				}
			} else {
				a[3]=0;
			}
		} else {
			a[2]=0;
		}
	} else {
		a[1]=0;
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}
