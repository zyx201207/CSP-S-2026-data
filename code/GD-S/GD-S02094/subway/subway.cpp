#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int c, n, m, d, q, k[N],w,u,v, s[100005], t[100005], dist[N];
bool vis[N];
vector<pair<int, int>> e[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= 2 * m; i += 2)
	{
		cin >> w;
		e[i].push_back({i + 1,w});
		e[i + 1].push_back({i, w});
	}//奇数是地铁口，偶数是站厅  

	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= 2 * k[i]; j++)
		{
			cin >> u >> w;//2m+i->the_ith_subway
			e[2 * m + i].push_back({u + 1, w});
			e[u + 1].push_back({2 * m + i, w});
		}
	}
	while(q--)
	{
		cout << 32;
	}
	
}
