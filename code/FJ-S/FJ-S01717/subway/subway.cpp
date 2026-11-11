#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+100;
ll c,n,m,d,q;//n=lines of sub,m=stations of sub
ll f[1000][1000],w[MAXN];
ll t[520][MAXN];
void floyd() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(f[i][k]+f[k][j]<f[i][j]) {
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
}
void solve1() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f[i][j]=0x3f3f3f3f3f3f3f3f;
			if(i==j) f[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		int s;
		cin>>s;
		for(int j=1; j<=s; j++) {
			int u;
			cin>>u;
			cin>>t[i][u];
			for(int k=1; k<i; k++) {
				if(t[k][u]) {
					f[i][k]=f[k][i]=min(f[k][i],t[k][u]+t[i][u]);
				}
			}
		}
	}
	floyd();
	while(q--) {
		int x,y;
		cin>>x>>y;
		ll res=0x3f3f3f3f3f3f3f3f;
		for(int i=1; i<=n; i++) {
			if(t[i][x]==0) {
				continue;
			}
			for(int j=1; j<=n; j++) {
				if(t[j][y]==0) {
					continue;
				}
				res=min(res,t[i][x]+t[j][y]+f[i][j]);
			}
		}
		cout<<w[x]+w[y]+res<<'\n';
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	solve1();
	return 0;
}