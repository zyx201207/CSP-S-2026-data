#include<bits/stdc++.h>
using namespace std;
const int MAXN=500,MAXM=5e5;
int c,n,m,d,q,k,a,t,w[MAXM+1];
long long f[MAXN+1][MAXN+1],ans;
vector<pair<int,int> > v[MAXM+1];
int main()
{
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        f[i][i]=0;
        for(int j=1;j<=k;j++)
        {
            cin>>a;
            cin>>t;
            for(int k=0;k<v[a].size();k++)
            {
                if(f[i][v[a][k].first]==-1)
                {
                    f[i][v[a][k].first]=t+v[a][k].second;
                    f[v[a][k].first][i]=t+v[a][k].second;
                }
                else
                {
                    f[i][v[a][k].first]=min(f[i][v[a][k].first],(long long)(t)+v[a][k].second);
                    f[v[a][k].first][i]=min(f[v[a][k].first][i],(long long)(t)+v[a][k].second);
                }
            }
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(f[i][j]!=-1&&f[i][k]!=-1)
                {
                    if(f[j][k]==-1)
                    {
                        f[j][k]=f[i][j]+f[i][k];
                    }
                    else
                    {
                        f[j][k]=min(f[j][k],f[i][j]+f[i][k]);
                    }
                }
            }
        }
    }
    while(q--)
    {
        cin>>a>>t;
        ans=LONG_LONG_MAX;
        for(int i=0;i<v[a].size();i++)
        {
            for(int j=0;j<v[t].size();j++)
            {
                ans=min(ans,f[v[a][i].first][v[t][j].first]+v[a][i].second+v[t][j].second);
            }
        }
        cout<<ans+w[a]+w[t]<<'\n';
    }
    return 0;
}