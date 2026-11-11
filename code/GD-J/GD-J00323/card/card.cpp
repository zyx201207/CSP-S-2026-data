#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 10;
int n,m,a[maxn],lst[maxn];
struct edge{int nxt,to;}e[maxn << 1];int head[maxn],tot;
void add_edge(int u,int v){e[++tot].nxt = head[u];head[u] = tot;e[tot].to = v;}
int siz[maxn],ans[maxn];
void dfs(int u,int fa)
{
    siz[u] = 1;
    for(int i = head[u];i;i = e[i].nxt)
    {
        int v = e[i].to;
        if(v == fa)continue;
        dfs(v,u);siz[u] += siz[v];
    }
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++)lst[a[i]] = i;
    for(int i = 1;i <= n;i++)add_edge(i,lst[a[i]] + 1),add_edge(lst[a[i]] + 1,i);
    dfs(n + 1,0);
    for(int i = 1;i <= n;i++)ans[a[i]] += siz[i];
    for(int i = 1;i <= m;i++)cout << ans[i] << " ";
    return 0;
}

/*
J 组越简单，S 组越难。
----
祈祷一下 RP++。
*/

/*
你看我手里的胭脂虫，像不像那晚春的花骨朵。
*/