#include<bits/stdc++.h>
using namespace std;
#define LL long long
int c;//unused
int n,m,d,q;
const LL MAXN=505,MAXM=5e5+8;
vector<int> a[MAXN];
int w[MAXM];
vector<int> t[MAXN];
vector<int> t2[MAXM];
vector<int> a2[MAXM];
LL dis[MAXN][MAXN];
int t3[MAXM][MAXN];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            a2[x].push_back(i);
            t[i].push_back(y);
            t2[x].push_back(y);
            t3[x][i]=y;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=2e17;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<a2[i].size();j++)
        {
            for(int k=0;k<a2[i].size();k++)
            {
                if(a2[i][j]!=a2[i][k])
                {
                    dis[a2[i][j]][a2[i][k]]=min(dis[a2[i][j]][a2[i][k]],(LL)t2[i][j]+t2[i][k]);
                    dis[a2[i][k]][a2[i][j]]=min(dis[a2[i][k]][a2[i][j]],(LL)t2[i][j]+t2[i][k]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(i!=j)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
                else dis[i][j]=0;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        LL ans=1e18;
        int s,t;
        cin>>s>>t;
        for(int j=0;j<a2[s].size();j++)
        {
            for(int k=0;k<a2[t].size();k++)
            {
                ans=min(ans,dis[a2[s][j]/*subwaynum*/][a2[t][k]/*subwaynum*/]+w[s]+w[t]+t3[s][a2[s][j]]+t3[t][a2[t][k]]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
