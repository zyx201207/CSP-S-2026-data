#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e5+5,N=505;
int x,y;
ll ans;
int c,n,m,d,p,w[M],a[N][M],t[N][M],num[N];
inline void dfs(int k,ll s, int o) {
	ll ss=s;
	if(k==y) {
		s+=w[y];
		ans=min(ans,s);
		return;
	}
	if(s>=ans) return;
	bool f=0;
	for(int i=1; i<=n; i++) {
		if(o==i) continue;
		f=0;
		for(int j=1; j<=num[i]; j++) {
			if(f) dfs(a[i][j],ss+t[i][j],i);
			if(a[i][j]==k) ss+=t[i][j],f=1;
		}
		ss=s;
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>num[i];
		for(int j=1; j<=num[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(p--) {
		ans=LLONG_MAX;
		cin>>x>>y;
		dfs(x,w[x],0);
		cout<<ans<<'\n';
	}
	return 0;
}


