#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
long long ans,vis[M],w[M],f[N][N];
map<pair<int,int>,long long>mp;
vector<int>v[N],s[M];
//void dfs(int x,long long sum,int t)
//{
//	vis[x]=min(vis[x],sum);
//	if(sum>=ans)
//		return;
//	if(x==t)
//	{
//		ans=min(ans,sum);
//		return;
//	}
//	for(int l:s[x])
//	{
//		for(int y:v[l])
//		{
//			long long res=sum+mp[{l,x}]+mp[{l,y}];
//			if(vis[y]>res)
//				dfs(y,res,t);
//		}
//	}
//}
//void solve1()
//{
//	while(q--)
//	{
//		ans=(1ll<<62);
//		int x,y;
//		scanf("%d%d",&x,&y);
//		memset(vis,0x3f,sizeof(vis));
//		dfs(x,0,y);
//		printf("%lld\n",ans+w[x]+w[y]);
//	}
//}
void solve2()//(i,j) i:line j:station v[line]=station s[station]=line
{
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		for(int x:s[i])
		{
			for(int y:s[i])
				f[x][y]=min(f[x][y],mp[{x,i}]+mp[{y,i}]);
		}
	}
	for(int i=1;i<=n;i++)	
		f[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--)
	{
		ans=(1ll<<62);
		int x,y;
		cin>>x>>y;
//		scanf("%d%d",&x,&y);
		for(int i:s[x])
		{
			for(int j:s[y])
				ans=min(ans,f[i][j]+mp[{i,x}]+mp[{j,y}]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
//		printf("%lld\n",ans+w[x]+w[y]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		cin>>w[i];
//		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
//		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;
			long long t;
			cin>>a>>t;
//			scanf("%d%lld",&a,&t);
			mp[{i,a}]=t;
			v[i].push_back(a);
			s[a].push_back(i);
		}
	}
//	if(c<=3)
//		solve1();
	solve2();
	return 0;
}
