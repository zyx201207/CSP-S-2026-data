#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[405],k[505],a[505][405],t[505][405];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> k[i];
		for(int j=1; j<=k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--) {
		int x,y,ans=0;
		cin >> x >> y;
		ans+=w[x]+w[y];
		for(int i=x; i<y; i++) ans+=t[i][i]+t[i][i+1];
		cout << ans << "\n";
	}
	return 0;
}
