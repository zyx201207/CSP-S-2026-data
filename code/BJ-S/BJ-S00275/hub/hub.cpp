#include<bits/stdc++.h>
using namespace std;
int c,t,p,l;
vector<int> g[1000001];
bool f[1000001];
void dfs(int step,int nw)
{
    if(step>l)
    {
        p=nw;
        l=step;
    }
    for(int i=0;i<g[nw].size();i++)
    {
        if(!f[g[nw][i]])
        {
            f[g[nw][i]]=1;
            dfs(step+1,g[nw][i]);
        }
    }
    return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(f,false,sizeof(f));
        l=0;
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,1);
        memset(f,false,sizeof(f));
        dfs(1,p);
        cout<<((l/3+1)-k/4)/3+1<<'\n';
    }
    return 0;
}
