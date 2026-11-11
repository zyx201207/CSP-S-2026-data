#include<iostream>

using namespace std;

const int N = 1e6 + 5;
int tot,he[N],ve[N],ne[N];
void add(int u,int v)
{
    ve[++tot] = v;
    ne[tot] = he[u];
    he[u] = tot;
}

int n,k,vis[N],col[N];
int f[100][100];
void clear()
{
    for(int i = 1; i <= n; i++) he[i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j) f[i][j] = n;
    for(int i = 1; i <= tot; i++) ve[i] = ne[i] = 0;
    tot = 0;
}

void dfs(int u,int fa)
{
    vis[u] = 1;
    for(int i = he[u]; i; i = ne[i])
    {
        int v = ve[i];
        if(v == fa || !col[v] || vis[v]) continue;
        dfs(v,u);
    }
}



void solve()
{
    cin >> n >> k; clear();
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        add(u,v); add(v,u);
        f[u][v] = f[v][u] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
        
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
    
    // for(int i = 1; i <= n; i++)
        // for(int j = 1; j <= n; j++)
            // cout << f[i][j] << " \n"[j == n];

    int ans = n;
    for(int i = 1; i < (1 << n); i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
            if(i >> j & 1) sum++;
        if(sum != k) continue;

        for(int j = 1; j <= n; j++)
        {
            if((i >> (j - 1)) & 1) col[j] = 1;
            else col[j] = 0;
            vis[j] = 0;
        }

        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(!col[j] || vis[j]) continue;
            cnt++; dfs(j,0);
        }
        if(cnt > 2) continue;

        // cout << i << "\n";
        // cout << "Yes\n";

        int res = 0;
        for(int u = 1; u <= n; u++)
        {
            if(col[u]) continue;
            int sum = n;
            for(int j = 1; j <= n; j++)
            {
                if(!col[j]) continue;
                sum = min(sum,f[u][j]);
            }
            // cout << u << " " << sum << "\n";
            res = max(sum,res);
        }
        // cout << "\n";
        ans = min(ans,res);
    }

    cout << ans << "\n";
}

int main()
{ 
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    // ios::sync_with_sydio(0);
    // cin.tie(0); cout.tie(0);

    int c,T; cin >> c >> T;
    while(T--) solve();
}