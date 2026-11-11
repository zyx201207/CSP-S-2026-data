#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
//char buf[1<<24],*p1,*p2;
//#define gc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<24,stdin),p1==p2)?EOF:*p1++
#define gc() getchar()
int read()
{
	int res=0;
	char c=gc();
	while(c<'0'||c>'9')
	{
		c=gc();
	}
	while(c>='0'&&c<='9')
	{
		res=(res<<1)+(res<<3)+(c^48);
		c=gc();
	}
	return res;
}
const ll INF=1e18;
int c,n,m,d,q;
int w[500005];
vector< pair<int,int> >a[500005];
ll f[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int len=read();
		for(int j=1;j<=len;j++)
		{
			int x=read(),y=read();
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int len=a[i].size();
		for(int j=1;j<len;j++)
		{
			for(int k=0;k<j;k++)
			{
				int u=a[i][j].first,v=a[i][k].first,x=a[i][j].second,y=a[i][k].second;
				f[u][v]=f[v][u]=min(f[u][v],1ll*x+1ll*y);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k||f[i][k]==INF)
			{
				continue;
			}
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int u=read(),v=read();
		int l1=a[u].size(),l2=a[v].size();
		ll ans=INF;
		for(int j=0;j<l1;j++)
		{
			for(int k=0;k<l2;k++)
			{
				ans=min(ans,f[a[u][j].first][a[v][k].first]+1ll*a[u][j].second+1ll*a[v][k].second); 
			}
		}
		printf("%lld\n",ans+1ll*w[u]+1ll*w[v]);
	}
	return 0;
}
