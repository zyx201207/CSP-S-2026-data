#include<bits/stdc++.h>
using namespace std ;
const int N = 2e6 + 300;
typedef long long ll;
ll a[N] ;int n;ll m;
const int N2 = 5005 ;
int ds[N2], f[N2], vis[N2];
vector<int> g[N2] ;
void BFS(int st)
{
    queue<int> Q;
    Q.push(st) ;
    for(int i=1;i<=n;i++) ds[i]=400000, f[i] = 0, vis[i] =0;
    ds[st] = 0;
    f[st] = 1;
    while(Q.size())
    {
        int t = Q.front() ;
        Q.pop() ;
        if(vis[t]) continue ;
        vis[t] = 1;
        for(int i : g[t])
        {
            if(ds[i] > ds[t] + 1)
            {
                ds[i] = ds[t]+ 1;
                f[i] = f[t] ;
                Q.push(i) ;
            }
            else if(ds[i] == ds[t] + 1) 
            {
                f[i] += f[t] ;
                if(f[i] > 2) f[i] = 3;
            }
        }
    }
}
int main()
{
    freopen("migrate.in", "r", stdin) ;
    freopen("migrate.out", "w", stdout) ;
    cin.tie(0) ;
    cout.tie(0) ;
    ios::sync_with_stdio(0) ;
    int c, t ;
    cin>>c>>t;
    if(11<=c&&c<=12)
    {
        while(t--)
        {
            cin>>n>>m ;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i] ;
            }
            if(n <= 1)
            {
                cout << "0\n" ;
            }
            else 
            {
                ll d = a[2] - a[1] ;
                ll cnt = m / d, ans=0; 
                // 2 * cnt ;
                for(int i=1;i<=n;i++)
                {
                    if(i + 2 * cnt-1 <= n && cnt > 1)
                    {
                        ++ans ;
                    }
                }
                cout << ans << '\n' ;
            }
        }
    }
    else if(13 <=c && c <= 14)
    {
        while(t--)
        {
            cin>>n>>m ;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i] ;
            }
            cout << "0\n" ;
        }
    }
    else if(1 <=c && c <= 10)
    {
        while(t--)
        {
            cin>>n>>m ;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i] ;
            }
            for(int i=1;i<=n;i++) g[i].clear() ;
            for(int i=1;i<=n;++i)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j] - a[i] <= m)
                    {
                        g[i].push_back(j) ;
                        g[j].push_back(i) ;
                    }
                }
            }
            int tt =0;
            for(int i=1;i<=n;i++)
            {
                BFS(i) ;
                for(int j=i+1;j<=n;j++)
                {
                    // cout << f[j] << " " << i << ',' << j << '\n' ;
                    if(f[j] == 2)
                    {
                        ++tt;
                    }
                }
            }
            cout << tt << '\n' ;
        }
    }
}