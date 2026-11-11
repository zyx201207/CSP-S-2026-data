#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
const int N=5e5+5;
int qread()
{
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res;
}
int c,n,m,d,q;
int w[N];
int k;
int x,y;
intt dis[505][505];
std::vector<std::pair<int,intt> > subway[N];
void Floyd()
{
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(std::pair<int,intt> x:subway[i]) for(std::pair<int,intt> y:subway[i])
		{
			int u=x.first,v=y.first;intt w=x.second,W=y.second;
			dis[u][v]=std::min(dis[u][v],w+W);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
}
intt dist(int x,int y)
{
	intt res=LLONG_MAX;
	for(std::pair<int,intt> u:subway[x]) for(std::pair<int,intt> v:subway[y])
		res=std::min(res,u.second+dis[u.first][v.first]+v.second);
	return res+w[x]+w[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		k=qread();
		for(int j=1;j<=k;j++)
		{
			x=qread(),y=qread();
			subway[x].push_back(std::make_pair(i,y));
		}
	}
	Floyd();
	while(q--)
	{
		x=qread(),y=qread();
		printf("%lld\n",dist(x,y));
	}
	return 0;
}
