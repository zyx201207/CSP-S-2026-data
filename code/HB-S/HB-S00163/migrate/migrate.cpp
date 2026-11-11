#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=2e18;
int c,t,n,d,x[305],f[305][305],g[305][305],s[305][305],ans;
int ABS(int a) {
	return a>0?a:-a;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i=1; i<=n; i++) cin >> x[i];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(j!=i&&ABS(x[i]-x[j])<=d) f[i][j]=1;
				else f[i][j]=INF;
				g[i][j]=f[i][j];
			}
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				if(f[i][k]==INF) continue;
				for(int j=1; j<=n; j++) {
					if(f[k][j]==INF) continue;
					f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				}
			}
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				if(g[i][k]==INF) continue;
				for(int j=1; j<=n; j++) {
					if(g[k][j]==INF) continue;
					if(g[i][k]+g[k][j]==f[i][j]) s[i][j]++;
					g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(s[i][j]==2) ans++;
			}
		}
		cout << ans << "\n";
		ans=0;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(s,0,sizeof(s));
	}
	return 0;
}
