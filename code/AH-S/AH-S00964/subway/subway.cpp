#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
ll c,n,m,d,q,w[505],dp[5005][5005],rch[5005][505],sz[505][505];
void floyd() {
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			if(i==j) continue;
			for(int k=1; k<=n; k++) {
				if(!rch[i][k] || !rch[j][k]) continue;
				for(int l=1; l<=sz[k][0]; l++) {
					if(i==l || j==l) continue;
					dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
				}
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) cin >> w[i];
	memset(dp,INT_MAX,sizeof dp);
	for(int i=1; i<=n; i++) {
		cin >> sz[i][0];
		for(int j=1; j<=sz[i][0]; j++) {
			int tm;
			cin >> sz[i][j] >> tm;
			rch[sz[i][j]][i]=tm;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=1; k<=n; k++) {
				if(!rch[i][k] || !rch[j][k]) continue;
				dp[i][j]=min(dp[i][j],rch[i][k]+rch[j][k]);
			}
		}
	}
	floyd();
	while(q--) {
		int st,sp;
		cin >> st >> sp;
		cout << dp[st][sp]+w[st]+w[sp] << endl;
	}
	return 0;
}

