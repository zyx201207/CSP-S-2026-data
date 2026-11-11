#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000002;

int c,T,n,k;
int dep[MAXN];
int fa[MAXN][22];
vector <int> links[MAXN];

void Dfs(int u,int father)
{
    fa[u][0] = father;
    dep[u] = dep[father] + 1;

    auto &link = links[u];
    for(auto v : link)
    {
        if(v == father)
            continue;
        Dfs(v,u);
    }
}

void CreateST()
{
    for(int i = 1;i <= 20;i++)
        for(int j = 1;j <= n;j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
}

int LCA(int x,int y)
{
    if(dep[x] < dep[y]) swap(x,y);
    for(int i = 20;i >= 0;i--)
        if(dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    if(x == y) return x;
    for(int i = 20;i >= 0;i--)
    {
        if(fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int Dis(int x,int y)
{
    return dep[x] + dep[y] - 2 * dep[LCA(x,y)];
}

int cnt;
int pre[MAXN];
bool bp[MAXN];

int Find(int x)
{
    if(pre[x] == x)
        return x;
    return pre[x] = Find(pre[x]);
}

void Join(int x,int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy)
    {
        pre[fx] = fy;
        cnt--;
    }
}

int Check()
{
    int cc = 0;
    for(int i = 1;i <= n;i++)
        cc += (int)bp[i];
    if(cc != k) return 0x3f3f3f3f;

    for(int i = 1;i <= n;i++) pre[i] = i; cnt = k;
    for(int i = 1;i <= n;i++)
    {
        if(!bp[i]) continue;
        for(int j = i + 1;j <= n;j++)
        {
            if(!bp[j]) continue;
            if(fa[i][0] == j || fa[j][0] == i)
                Join(i,j);
        }
    }
    if(cnt > 2) return 0x3f3f3f3f;

    int maxv = 0;
    for(int i = 1;i <= n;i++)
    {
        int minv = 0x3f3f3f3f;
        for(int j = 1;j <= n;j++)
        {
            if(!bp[j])
                continue;
            minv = min(minv,Dis(i,j));
        }
        maxv = max(maxv,minv);
    }

    return maxv;
}

int ans;
void Dfss(int step)
{
    if(step == n + 1)
    {
        ans = min(ans,Check());
        return;
    }

    bp[step] = true;
    Dfss(step + 1);
    bp[step] = false;
    Dfss(step + 1);
}

void Do()
{
    ans = 0x3f3f3f3f;
    Dfss(1);
    cout << ans << '\n';
}

int dis[MAXN];
void Find(int u,int father)
{
    dis[u] = dis[father] + 1;
    auto &link = links[u];
    for(auto v : link)
    {
        if(v == father)
            continue;
        Find(v,u);
    }
}

void Clear()
{
    for(int i = 0;i <= n;i++)
    {
        bp[i] = dep[i] = dis[i] = 0;
        memset(fa[i],0,sizeof(fa[i]));
        links[i].clear();
    }
}

mt19937_64 RAND(time(0));
int arr[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin >> c >> T;
    while(T--)
    {
        Clear();
        cin >> n >> k;
        for(int i = 1;i < n;i++)
        {
            int u,v;
            cin >> u >> v;
            links[u].push_back(v);
            links[v].push_back(u);
        }

        Dfs(1,0);
        CreateST();
        if(n <= 10)
        {
            Do();
            continue;
        }

        Find(1,0);
        int s = 0,maxs = 0;
        for(int i = 1;i <= n;i++)
        {
            if(dis[i] > maxs)
            {
                maxs = dis[i];
                s = i;
            }
        }

        Find(s,0);
        int t = 0; maxs = 0;
        for(int i = 1;i <= n;i++)
        {
            if(dis[i] > maxs)
            {
                maxs = dis[i];
                t = i;
            }
        }

        int len = Dis(s,t);
        ans = len / 4 + (len % 4 != 0);
        for(int i = 1;i <= n;i++) arr[i] = i;
        for(int ttt = 1;ttt <= 20000000 / n / n;ttt++)
        {
            random_shuffle(arr + 1,arr + n + 1);
            for(int i = 1;i <= k;i++) bp[arr[i]] = true;
            ans = min(ans,Check());
            for(int i = 1;i <= k;i++) bp[arr[i]] = false;
        }
        
        cout << ans << '\n';
    }

    return 0;
}
