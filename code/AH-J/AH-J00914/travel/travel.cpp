#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int r1,x1,r2,x2;
	char r3,x3;
	cin>>r1>>r2>>r3;
	cin>>x1>>x2>>x3;
	bool rx=(r1==x1);
	cout<<rx;
	if (!rx) {
		cout<<"000";
		return 0;
	}
	rx=(r2==x2);
	cout<<rx;
	if (!rx) {
		cout<<"00";
		return 0;
	}
	int r=r3-'A'+1;
	int x=x3-'A'+1;
	bool t=(r<=3 && x<=3 || r>=4 && x>=4);
	cout<<t;
	if (t) {
		cout<<(abs(r-x)==1);
	} else cout<<0;
	return 0;
}
