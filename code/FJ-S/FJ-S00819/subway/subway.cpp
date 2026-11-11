#include <bits/stdc++.h>
using namespace std;
const long long N = 800005;
long long c,n,m,d,q,k,a,fa[N],x,y;
long long w[N],t,depth[N],sum[N],f[N][21];
struct Edge
{
	long long u,v,w;
};
vector<Edge> e;
vector<pair<long long,long long>> p[N];
bool cmp(Edge l,Edge r)
{
	return l.w < r.w;
}
long long find(long long x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void dfs(long long u,long long fa)
{
	for (long long i = 0;i < p[u].size();i++){
		long long v = p[u][i].first,w = p[u][i].second;
		if (v == fa)
		    continue;
		depth[v] = depth[u] + 1;
		sum[v] = sum[u] + w;
		f[v][0] = u;
		dfs(v,u);
	}
}
long long lca(long long u,long long v)
{
	if (depth[u] < depth[v])
	    swap(u,v);
	long long k = depth[u] - depth[v];
    for (long long i = 0;i <= 20;i++)
        if (k & (1 << i))
            u = f[u][i];
    if (u == v) return u;
    for (long long i = 20;i >= 0;i--){
        if (f[u][i] != f[v][i]){
        	u = f[u][i];
        	v = f[v][i];
		}
    }
    return f[u][0];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1;i <= m;i++)
	    cin >> w[i];
	for (long long i = 1;i <= n;i++){
		cin >> k;
		for (long long j = 1;j <= k;j++){
			cin >> a >> t;
			e.push_back((Edge){a,i + m,t
			});
		}
	}
	sort(e.begin(),e.end(),cmp);
	for (long long i = 1;i <= m + n;i++)
	    fa[i] = i;
	for (long long i = 0;i < e.size();i++){
		long long u,v,w;
		u = e[i].u,v = e[i].v,w = e[i].w;
		if (find(u) == find(v))
		    continue;
		fa[find(u)] = find(v);
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	dfs(1,0);
	for (long long i = 1;i <= 20;i++)
	    for (long long u = 1;u <= n + m;u++)
	        f[u][i] = f[f[u][i - 1]][i - 1];
	while (q--){
		cin >> x >> y;
		cout << sum[x] + sum[y] - 2 * sum[lca(x,y)] + w[x] + w[y] << endl;
	}
}
