#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 550,M=505000;
const ll inf = 1152921504606846976;
ll n, m,i,j,d,q,ce,ans,s,e;
ll w[M],k[M],a,t, dd[M];
struct node{
	ll v;
	ll w;
};
vector<node>turn[M],getin[N];
void dfs(ll u, ll cnt)
{
//	cout << u << " " << cnt << endl;
	dd[u] = min(dd[u], cnt);
	if (u == e)
	{
		ans = min(ans, cnt);
		return;
	}
	if (cnt > ans) return;
	for (auto v : turn[u])
	{
		ll sub = v.v;
		ll w = v.w;
		for (auto v2: getin[sub])
		{
			ll nxt = v2.v;
			ll w2 = v2.w;
			ll cnt2 = cnt + w +w2;
			if (cnt2 < ans && cnt2 < dd[nxt]) dfs(nxt, cnt2);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin >> ce >> n >> m >> d >> q;
	for (i=1; i<=m; i++)
	{
		cin >> w[i];
	}
	for (i=1; i<=n; i++)
	{
		cin >> k[i];
		for (j=1; j<=k[i]; j++)
		{
			cin >> a >> t;
			turn[a].push_back({i,t});
			//从 a地铁站的站厅 到 i号线的站台 需要 t的时间 
		    getin[i].push_back({a,t});
		    //从i号线走到a地铁站的站厅 需要t的时间 
		}
	}
	while (q--)
	{
		
		cin >> s >> e;
		
		if (s==e) {
			cout << 0 << endl;
		}else{
			memset(dd,0x3f,sizeof(dd));
			ans = inf;
			dfs(s, 0);
			cout << ans + w[s] + w[e] << endl;
		}
		
	}
	fclose(stdin);fclose(stdout); 
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
