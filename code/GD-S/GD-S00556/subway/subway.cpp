#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=500005,N=505;
int c,n,m,d,q,f[N][N],w[M];
struct line
{
	int id,w;
};
vector<line> sta[M]; 
void solve()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int sta_num,sta_w;
			cin>>sta_num>>sta_w;
			sta[sta_num].push_back({i,sta_w});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<sta[i].size();j++)
		{
			for(int k=0;k<sta[i].size();k++)
			{
				if(j==k) continue;
				int a=sta[i][j].id,b=sta[i][k].id;
				f[a][b]=min(f[a][b],sta[i][j].w+sta[i][k].w); 
				f[b][a]=min(f[b][a],sta[i][j].w+sta[i][k].w); 
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
		int u,v,ans=0x3f3f3f3f3f3f3f3f;
		cin>>u>>v;
		for(int i=0;i<sta[u].size();i++)
		{
			for(int j=0;j<sta[v].size();j++)
			{
				int a=sta[u][i].id,b=sta[v][j].id;
				ans=min(ans,f[a][b]+sta[u][i].w+sta[v][j].w);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
} 
