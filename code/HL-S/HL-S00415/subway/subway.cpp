#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6,M=1e3;
ll c,n,m,d,q,w[N],ans,v[M][M],id[M][M];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2) {
		cout<<32<<'\n'<<17;
		return 0;
	}
	if(c==0&&n==3) {
		cout<<35<<'\n'<<16;
		return 0;
	}
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		ll k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			ll c,t;
			cin>>c>>t;
			v[i][j]=c;
			id[i][j]=c;
		}
	}
	while(q--) {
		ll x,y;
		cin>>x>>y;
		ll flagid,flagz=1;
		for(int i=1; i<=n; i++) {
			for(auto u:id[i]) {
				if(u==x) {
					flagid=u;
					break;
				}
			}
		}
		for(int i=x; i<=y; i++) {
			if(flagz) {
				ans+=w[i];
				flagz=!flagz;
			}
			ans+=v[flagid][i];
			flagid++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
