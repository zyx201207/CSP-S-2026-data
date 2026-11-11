#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
constexpr int maxn=5010,inf=0x3fffffff;
int c,n,m,d,q;
int w[maxn];
vector<pii > e[maxn];
int t[maxn][maxn];
int ed;
int ans;
int v[maxn];
void dfs(int x,int lt,int num)
{
    // cerr << x << endl;
    // for (int i=1;i<=m;i++)
    //     cerr << v[i] << " ";
    // cerr << endl;
    if (x == ed)
        return ans=min(ans,num+t[lt][x]),void();
    if (v[x]) return;
    v[x]=1;
    for (pii i:e[x])
    {
        int y=i.fi,li=i.se;
        if (lt!=li)
            dfs(y,li,num+t[lt][x]+t[li][x]);
        else
            dfs(y,li,num);
    }
    v[x]=0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
        cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        int k;cin >> k;
        int x;cin >> x;
        int lt=x;
        cin >> t[i][x];
        for (int j=1;j<k;j++)
        {
            int x;cin >> x;
            e[x].pb({lt,i}),e[lt].pb({x,i});
            cin >> t[i][x];
            lt=x;
        }
    }
    // for (int i=1;i<=m;i++)
    // {
    //     cerr << "------------------" << endl;
    //     cerr << i << endl;
    //     for (pii j:e[i])
    //         cerr << j.fi << " " << j.se << endl;
    //     cerr << "------------------" << endl;
    // }
    while (q--)
    {
        int x,y;cin >> x >> y;
        ans=inf;
        for (int i=1;i<=m;i++)
            v[i]=0;
        ed=y;
        // cerr << "**************" << endl;
        dfs(x,0,0);
        // cerr << "**************" << endl;
        cout << ans+w[x]+w[y] << endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*qing song zhui ji..*/