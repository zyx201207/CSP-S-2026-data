#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define ll long long
ll c,n,m,d,q,ct[500005],ans = 3e18,g[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m; ++ i)
	{
		cin >> ct[i];
		for(int j = 1;j <= m; ++ j) g[i][j] = 1e18;
	}
	for(int i = 1;i <= n; ++ i)
	{
		int ci;
		cin >> ci;
		for(int j = 1;j <= ci; ++ j)
		{
			ll v,val;
			cin >> v >> val;
			g[i][v] = min(g[i][v],val);
		}
	}
	while(q --)
	{
		ans = 3e18;
		int st,en;
		cin >> st >> en;
		for(int k = 1;k <= m; ++ k)
		{
			ans = min(ans,g[st][k] + g[k][en]);
		}
		ans += ct[st] + ct[en];
		cout << ans << '\n';
	}
	return 0;
}
