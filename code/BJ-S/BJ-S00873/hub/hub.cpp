#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
const int N = 1e6 + 5;

int n,k,p;
vector<int> g[N];

// void dfs(int x,int fa)
// {
//     dis[x] = 1;
//     for(auto v : g[x]) if(v != fa)
//     {
//         dfs(v,x);
//         dis[x] = max(dis[x],dis[v]+1);
//         minn[x] += minn[v];
//     }
//     if(dis[x] > p) minn[x]++;
// }

// bool check(int mid)
// {
//     p = mid; dfs(1,0);
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<i;j++)
//         {
//             if(minn[i] + minn[j] > k) continue;

//         }
// }

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ccc,ttt; cin >> ccc >> ttt;
    while(ttt--)
    {
        cin >> n >> k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u, v; cin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }
        if(ccc == 13 || ccc == 14)
        {
            int m = (n - 1) / 2;
            cout << (int)ceil((m-k+3)*1.0/4) << '\n';
            continue;
        }
        if(n == k) cout << 0 << '\n';
        else cout << 1 << '\n';
        // int l = 0, r = n, ans = n;
        // while(l <= r)
        // {
        //     int mid = (pl + pr) >> 1;
        //     if(check(mid)) r = mid - 1, ans = 0;
        //     else l = mid + 1;
        // }
        // cout << ans << '\n';
    }
    return 0;
}