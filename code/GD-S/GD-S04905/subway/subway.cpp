# include <cstdio>
# include <vector>
# define int long long
using namespace std;
const int inf=100000000000000000;
int Tid,n,m,D,Q,h[1000007],dis[727][727];
struct node{int x,y;};
vector <node> cc[1000007];
int min(int x,int y){return x<y?x:y;}
int read()
{
	char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	int ans=0;
	while(ch>='0'&&ch<='9') ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&Tid,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++) h[i]=read();
	for(int i=1;i<=n;i++)
	{
		int len=read();
		for(int j=1;j<=len;j++)
		{
			int x=read(),y=read();
			cc[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j]=inf;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int sz=cc[i].size();
		for(int j=0;j<sz;j++)
		for(int k=j+1;k<sz;k++)
		{
			int x=cc[i][j].x,y=cc[i][k].x,z=cc[i][j].y+cc[i][k].y;
			dis[x][y]=min(dis[x][y],z);
			dis[y][x]=min(dis[y][x],z);
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int happy=1;happy<=Q;happy++)
	{
		int x=read(),y=read();
		int ans=inf,sz1=cc[x].size(),sz2=cc[y].size();
		for(int i=0;i<sz1;i++)
		for(int j=0;j<sz2;j++)
			ans=min(ans,cc[x][i].y+cc[y][j].y+dis[cc[x][i].x][cc[y][j].x]);
		printf("%lld\n",ans+h[x]+h[y]);
	}
	return 0;
}
