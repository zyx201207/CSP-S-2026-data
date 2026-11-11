#include<bits/stdc++.h>
using namespace std;
int c,tc,n,k,ans,x,y;
bool st[100005],ch[100005];
bitset<64> bs;
vector<int> v[100005];
void chk(int x,int fa)
{
    if(!st[x]) return;
    ch[x]=1;
    for(int i = 0; i < v[x].size(); i++)
    {
        if(v[x][i]!=fa)
        {
            chk(v[x][i],x);
        }
    }
}
int dfs(int x,int fa,int dis)
{
    if(st[x]) return dis;
    int ret=10000000;
    for(int i = 0; i < v[x].size(); i++)
    {
        if(v[x][i]!=fa)
        {
            ret=min(ret,dfs(v[x][i],x,dis+1));
        }
    }
    return ret;
}
void solve()
{
    cin>>n>>k;
    for(int i = 1; i <= n; i++) v[i].clear();
    for(int i = 1; i < n; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans=10000000;
    for(int i = 1; i < (1<<n); i++)
    {
        bs=i;
        if(bs.count()!=k) continue;
        for(int j = 1; j <= n; j++)
        {
            st[j]=bs[j-1];
            ch[j]=0;
        }
        int ncnt=0;
        for(int j = 1; j <= n; j++)
        {
            if(st[j]&&(!ch[j]))
            {
                chk(j,0);
                ncnt++;
            }
        }
        if(ncnt>2) continue;
        int ndis=-1;
        for(int j = 1; j <= n; j++) ndis=max(ndis,dfs(j,0,0));
        ans=min(ans,ndis);
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>tc;
    while(tc--)
    {
        solve();
    }
}