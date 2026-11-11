#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505],a[505][500005],f[505][500005];
int t2021[500005];
bool vis[500005];
int x,y;
vector<pair<int,int> > ln[500005];
vector<pair<int,int> > t[500005];
int dfs(int x,int y,int l)
{
    if(x==y) return l;
    vis[x]=1;
    int ans=0x3f3f3f3f;
    for(int i=0;i<t[x].size();i++)
    {
        if(!vis[t[x][i].first]) ans=min(ans,dfs(t[x][i].first,y,l+t[x][i].second));
    }
    vis[x]=0;
    return ans;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>f[i][j];
            ln[a[i][j]].push_back({i,f[i][j]});
        }
    }
    if(c<=3||(c>=7&&c<=11))
    {
        for(int i=1;i<=n;i++)
        {
            for(int u=1;u<=k[i];u++)
            {
                for(int v=1;v<=k[i];v++)
                {
                    if(u!=v)
                    {
                        t[a[i][u]].push_back({a[i][v],f[i][u]+f[i][v]});
                        t[a[i][v]].push_back({a[i][u],f[i][u]+f[i][v]});
                    }
                }
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>x>>y;
            cout<<dfs(x,y,0)+w[x]+w[y]<<endl;
        }
    }
    if(c==20||c==21)
    {
        memset(t2021,0x3f3f3f3f,sizeof(t2021));
        for(int i=1;i<=m;i++)
        {
            if(ln[i][0].first==1&&ln[i][1].first==2) t2021[i]=ln[i][0].second+ln[i][1].second;
        }
        sort(t2021+1,t2021+1+m);
        for(int i=1;i<=q;i++)
        {
            cin>>x>>y;
            if(ln[x].size()==ln[y].size()==1)
            {
                if(ln[x][0].first==ln[y][0].first) cout<<w[x]+w[y]+ln[x][0].second+ln[y][0].second<<endl;
                else cout<<w[x]+w[y]+ln[x][0].second+ln[y][0].second+t2021[1]<<endl;
            }
            else if(ln[x].size()==ln[y].size()==2)
            {
                cout<<w[x]+w[y]+min(ln[x][0].second+ln[y][0].second,min(ln[x][1].second+ln[y][1].second,min(ln[x][0].second+ln[y][1].second+t2021[1],ln[x][1].second+ln[y][0].second+t2021[1])))<<endl;
            }
            else if(ln[x].size()==1)
            {
                cout<<w[x]+w[y]+min(ln[x][0].second+ln[y][ln[x][0].first-1].second,ln[x][0].second+ln[y][2-ln[x][0].first].second+t2021[1])<<endl;
            }
            else
            {
                cout<<w[x]+w[y]+min(ln[y][0].second+ln[x][ln[y][0].first-1].second,ln[y][0].second+ln[x][2-ln[y][0].first].second+t2021[1])<<endl;
            }
        }
    }
}
//add w[i]!!
