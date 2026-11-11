#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,x[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		int y=x[2]-x[1];
		if(d<abs(y))	cout<<0<<"\n";
		else cout<<abs(d)/abs(y)+2;
	}
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
