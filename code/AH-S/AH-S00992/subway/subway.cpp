#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e2 + 5, M = 5e5 + 5;
int c,n,m,d,q,x,y;
bool v[M];
long long ans=1e18,w[M],k[N],a[N][M],t[N][M];
void dfs1(int step, long long sum) {
	if (step==m) {
		ans=min(ans,sum);
		return;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k[i]; j++) {
			if (a[i][j]);
			dfs(step,sum);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>w[i];
	for (int i=1; i<=n; i++) {
		cin>>k[i];
		for (int j=1; j<=k[i]; j++) cin>>a[i][j]>>t[i][j];
	}
	while (q--) {
		cin>>x>>y;
		if (c>=12 && c<=19) {
			dfs1(x,0);
			continue;
		}
	}
	return 0;
}
