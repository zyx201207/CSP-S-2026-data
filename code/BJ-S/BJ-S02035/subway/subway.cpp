#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int v;
    ll w;
}in;
int nn[505],nm[500005];
ll exr[500005],ti[505][505];
vector<node> p[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,m,Ma,T,a,mm=0,st,la;
    ll ans;
    cin>>c>>n>>m>>Ma>>T;
    for(int i=1;i<=m;i++)
    {
        cin>>exr[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
                ti[i][j]=1e18;
        }
        cin>>nn[i];
        in.v=i;
        for(int j=1;j<=nn[i];j++)
        {
            cin>>a>>in.w;
            p[a].push_back(in);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0,x=p[i].size();j<x-1;j++)
        {
            for(int k=0;k<x;k++)
            {
                if(ti[p[i][j].v][p[i][k].v]>p[i][j].w+p[i][k].w)
                {
                    ti[p[i][j].v][p[i][k].v]=p[i][j].w+p[i][k].w;
                    ti[p[i][k].v][p[i][j].v]=p[i][j].w+p[i][k].w;
                }
            }
        }
    }
    // cout<<"1";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ti[i][j]<1e18&&i!=j)
            {
                for(int k=1;k<=n;k++)
                {
                    if(k!=i&&k!=j&&ti[i][k]<1e18)
                    {
                        if(ti[j][k]>ti[j][i]+ti[i][k])
                            ti[k][j]=ti[j][k]=ti[j][i]+ti[i][k];
                    }
                }
            }
        }
    }
    while(T--)
    {
        cin>>st>>la;
        ans=1e18;
        for(int i=0,x=p[st].size();i<x;i++)
        {
            for(int j=0,y=p[la].size();j<y;j++)
            {
                if(ans>ti[p[st][i].v][p[la][j].v]+p[st][i].w+p[la][j].w)
                    ans=ti[p[st][i].v][p[la][j].v]+p[st][i].w+p[la][j].w;
            }
        }
        cout<<exr[st]+exr[la]+ans<<"\n";
    }
    return 0;
}