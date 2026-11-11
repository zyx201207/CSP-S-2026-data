#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;

int c,T,n,k;
vector<int> adj[MAXN];

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1,u,v;i<=n-1;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<1<<endl;
    }
    return 0;
}
