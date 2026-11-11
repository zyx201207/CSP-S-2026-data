#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1010100],f[510][510];
vector<pair<long long,long long> > v[1010100];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    memset(f,0x3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
        int k;
        cin>>k;
        while(k--)
        {
            int a,t;
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto h:v[i])
        {
            for(auto ff:v[i])
            {
                f[h.first][ff.first]=min(f[h.first][ff.first],h.second+ff.second);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<0<<endl;
            continue;
        }
        long long ans=1e18;
        for(auto g:v[x])
        {
            for(auto h:v[y])
            {
                ans=min(ans,f[g.first][h.first]+g.second+h.second+w[x]+w[y]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
