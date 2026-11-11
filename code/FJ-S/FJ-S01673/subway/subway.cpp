#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=506,M=5e5+6;
int w[M],e[N][N],a[N],b[N];
struct node
{
	signed dian;
	int quan;
};
vector<node> jl[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(e,63,sizeof(e));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) e[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			jl[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		for(auto &x:jl[i])
		{
			a[++cnt]=x.dian,b[cnt]=x.quan;
		}
		for(int j=1;j<=cnt;j++)
			for(int k=j;k<=cnt;k++)
			{
				int x=a[j],y=a[k],quan=b[j]+b[k];
				e[x][y]=min(e[x][y],quan),e[y][x]=min(e[y][x],quan);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	//cout<<"666"<<endl;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto &xx:jl[x])
			for(auto &yy:jl[y])
				ans=min(ans,e[xx.dian][yy.dian]+xx.quan+yy.quan);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

