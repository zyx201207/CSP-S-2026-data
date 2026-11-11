#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010];
int jl[2510][2510],n_eed[2510],change[2510];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int tblg=1; tblg<=t; tblg++) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		long long c=a[2]-a[1];
		bool p=0;
		for(int i=2; i<n; i++) {
			if(a[i+1]-a[i]!=c) {
				p=1;
				break;
			}
		}
		if(!p) {
			c=abs(c);
			if(c*2>d)cout<<0<<'\n';
			else {
				int o=d/c*2-1;
				long long y=0;
				cout<<max(n-o,y)<<'\n';
			}
		}
	}
	return 0;
}
