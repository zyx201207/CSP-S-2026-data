#include <bits/stdc++.h>
using namespace std;

int c, t;
struct edge
{
	int v, next;
}e[4000005];
int head[2000005];
int n, k;

void init()
{
	memset(head, 0, sizeof(head));
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		init();
		cin >> n >> k;
		for (int i = 1;i < n;i++)
		{
			int u, v;
			cin >> u >> v;
			e[(i << 1) - 1].v = v;
			e[(i << 1) - 1].next = head[u];
			head[u] = (i << 1) - 1;
			e[i << 1].v = u;
			e[i << 1].next = head[v];
			head[v] = i << 1;
		}
		
	}
	return 0;
}
