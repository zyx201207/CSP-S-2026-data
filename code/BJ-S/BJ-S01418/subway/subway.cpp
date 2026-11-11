#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Node
{
	int v;
    long long w;
};
long long f[505][505],w[N];
vector<Node> shu[N];
int main()
{ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e17;
    for(int i=1;i<=n;i++)f[i][i]=0;
	
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
            int a,t;
			cin>>a>>t;
			shu[a].push_back((Node){i,t});
		}
	}
    for(int i=1;i<=m;i++)
    {
        for(auto v:shu[i])
        {
            for(auto vv:shu[i])
            {
                if(v.v!=vv.v)f[v.v][vv.v]=min(f[v.v][vv.v],v.w+vv.w);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        long long ans=1e17;
        for(auto u:shu[x])
        {
            for(auto v:shu[y])
            {
                ans=min(ans,f[u.v][v.v]+u.w+v.w);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
	return 0;
}