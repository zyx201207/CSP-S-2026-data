#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define maxn 500005
using namespace std;
bool st;
int n,m,d,q,x,y,z,w[maxn],dist[505][505];
vector<pii> to[maxn];
bool en;
signed main(){
	#ifndef LOCAL
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cerr << (&en-&st)/1048576.0 << "\n";
	memset(dist,0x3f,sizeof(dist));
	cin >> x >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		cin >> x,dist[i][i] = 0;
		while (x--) cin >> y >> z,to[y].push_back({i,z});
	}
	for (int i = 1;i <= m;i++)
		for (pii j : to[i])
			for (pii k : to[i])
				dist[j.fi][k.fi] = min(dist[j.fi][k.fi],j.se+k.se);
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	while (q--){
		cin >> x >> y;
		int ans = 1e18;
		for (pii i : to[x])
			for (pii j : to[y])
				ans = min(ans,dist[i.fi][j.fi]+i.se+j.se);
		cout << ans+w[x]+w[y] << "\n";
	}
	cerr << clock() << "\n";
	return 0;
}
/*
半小时切 T1T2，蒸蒸日上啊！ 
md做不出来 T3，蒸不动了。 
果然提前一天__一发没用啊，239已坠机。 
*/
