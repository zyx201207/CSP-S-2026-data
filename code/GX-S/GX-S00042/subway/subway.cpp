#include<cstdio>
#include<vector>

using std::vector;

struct e
{
	int v,w;
};

constexpr int N=501,M=5e5+1,D=21;
constexpr long long INF=1e18;

int c,n,m,d,q;
int w[M];
long long dis[N][N];
vector<vector<e>> edge1,edge2;

inline long long min(long long x,long long y)
{
	return x<y?x:y;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)
		scanf("%d",w+i);
	edge1.resize(m+1),edge2.resize(n+1);
	for(int i=1,k;i<=n;++i)
	{
		scanf("%d",&k);
		for(int j=1,a,t;j<=k;++j)
		{
			scanf("%d %d",&a,&t);
			edge1[a].push_back({i,t});
			edge2[i].push_back({a,t});
		}
	}

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j) dis[i][j]=INF;

	for(int i=1;i<=n;++i)
	{
		for(auto b2:edge2[i])
			for(auto b1:edge1[b2.v])
				dis[i][b1.v]=min(dis[i][b1.v],b1.w+b2.w);
	}

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

	for(int i=1,x,y;i<=q;++i)
	{
		scanf("%d %d",&x,&y);
		long long res=INF;
		for(auto b1:edge1[x])
			for(auto b2:edge1[y])
				res=min(res,b1.w+b2.w+dis[b1.v][b2.v]);
		printf("%lld\n",res+w[x]+w[y]);
	}
}
