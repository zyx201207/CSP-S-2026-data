#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2222222;
const int inf = 1e17;

int c, T;
int n, d, ans;

int a[N];

struct Node
{
	int a;
	int d;
};

queue<Node> q;

bool BFS(int s, int t)
{
	while(q.size()) q.pop();
	Node u;
	q.push({s, 0});
	int mind = inf, cnt = 0;
	for(int i = s; i < t; i++) if(a[i + 1] - a[i] > d) return 0;
	while(q.size())
	{
		u = q.front();
		q.pop();
		if(cnt > 2) return 0;
		if(u.a == t && u.d > mind) break;
		if(u.a == t && u.d < mind)
		{
			mind = u.d;
		}
		if(u.a == t)
		{
			cnt++;
			continue;
		}
		for(int i = u.a + 1; a[i] - a[u.a] <= d && i <= t; i++)
		{
			q.push({i, u.d + 1});
		}
	}
	if(cnt == 2) return 1;
	return 0;
}

void DEINOS_PHAINEIN()
{
	ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			ans += BFS(i, j);
		}
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	
	while(T--) DEINOS_PHAINEIN();
	
	return 0;
}
