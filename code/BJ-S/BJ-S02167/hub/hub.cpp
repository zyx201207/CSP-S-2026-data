#include <bits/stdc++.h>
using namespace std;
#define ll long long
int _,T,n,k;
vector<int> g[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_>>T;
    while(T--) solve();
    return 0;
}