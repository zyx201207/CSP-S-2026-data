#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int a[maxn];
int p[maxm];
int l[maxm];
int k[maxm];
int ans[maxm];
vector<int> g[maxm];
int dfs(int cur)
{
    //cout<<cur<<endl;
    for(int i=0; i<g[cur].size(); i++)
    {
        k[cur]+=dfs(g[cur][i]);
    }
    ans[cur]+=k[cur];
    return k[cur];
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int tmp=-1;
    for(int i=n; i>=1; i--)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(p[a[i]]==0)
        {
            p[a[i]]=i;
            if(i>1)l[a[i]]=a[p[a[i-1]]];
            else l[a[i]]=0;
            k[a[i]]=1;
            if(tmp==-1)tmp=a[i];
        }
        else
        {
            k[a[i]]++;
        }
    }
    for(int i=1; i<=m; i++)
    {
        g[l[i]].push_back(i);
    }
    /*
    for(int i=1; i<=m; i++)
    {
        cout<<i<<":";
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=m; i++)
    {
        cout<<k[i]<<" ";
    }
    cout<<endl;
    */
    dfs(tmp);
    for(int i=1; i<=m; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
