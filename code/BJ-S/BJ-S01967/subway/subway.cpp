#include <bits/stdc++.h>
using namespace std;
struct stat
{
    int id;
    int w;
    int t[20]={0};
};
stat st[500002];
vector<pair<stat,int> > v[502];
int c,n,m,d,q,mintr;
bool vis[502];
void dfs(int line,int now,int en,int cnt)
{
    //cout<<line<<' '<<now<<' '<<en<<' '<<cnt<<endl;
    for(int i=0;i<v[line].size();i++)
    {
        stat tmp=v[line][i].first;
        if(tmp.id==en)
        {
            mintr=min(mintr,cnt);
        }
        if(tmp.id==now)
            continue;
        else
        {
            for(int j=1;j<=d;j++)
            {
                if(j!=line&&tmp.t[j]!=0)
                {
                    vis[j]=1;
                    dfs(j,tmp.id,en,cnt+1);
                    vis[j]=0;
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int T;
    for(int i=1;i<=m;i++)
    {
        cin>>st[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            st[a].t[i]=t;
            T=t;
            v[i].push_back({st[a],t});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        mintr=2147483647;
        for(int i=1;i<=d;i++)
        {
            if(st[x].t[d]!=0)
            {
                vis[x]=1;
                dfs(i,x,y,1);
                vis[x]=0;
            }
        }
        cout<<mintr*T*2+st[x].w+st[y].w<<endl;
    }
    return 0;
}
