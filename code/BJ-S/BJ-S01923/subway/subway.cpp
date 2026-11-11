#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e2+8, MAXK = 5e5+8;

vector<pair<int, int>> edges[MAXN];
int c, n, m, d, q,dsu[MAXN << 2];
ll w[MAXN];

int find(int u)
{
    return dsu[u] == u ? u : find(dsu[u]);
}
void unite(int u, int v)
{
    dsu[find(u)] = find(v);
}

void bfs(int s, int e)
{

}
int main()
{
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1, k;i <= n;i++)
    {
        cin >> k;
        for(int j = 1, a, t;j <= k;j++)
        {
            cin >> a >> t;
            edges[i].push_back({a, t});
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
    }
    return 0;
}
