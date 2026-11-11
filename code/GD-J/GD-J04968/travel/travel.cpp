#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(!(a[0]==c[0]&&a[1]==c[1])) {
		cout<<"0000"<<endl;
		return 0;
	}
	if(!(b[0]==d[0]&&b[1]==d[1])) {
		cout<<"1000"<<endl;
		return 0;
	}
	if(!(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))) {
		cout<<"1100"<<endl;
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C') {
		if(!(((b[2]>d[2])?b[2]-d[2]:d[2]-b[2])==1)) {
			cout<<"1110"<<endl;
			return 0;
		} else {
			cout<<"1111"<<endl;
			return 0;
		}
	} else {
		cout<<"1111"<<endl;
		return 0;
	}
	return 0;
}
