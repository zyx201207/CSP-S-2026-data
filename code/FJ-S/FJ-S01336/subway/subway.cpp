#include<bits/stdc++.h>//long long
using namespace std;
const long long N=5e2+11,M=5e5+11,D=21,INF=0x7ffffffffffffff;
long long n,m,w[M],d[M][D],tim[M][D],cnt[N],dis[N][N];
vector<long long> a[N],t[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long id,dd,q,x,y,dan;
	cin>>id>>n>>m>>dd>>q;
	for(long long i=1; i<=m; i++)
		scanf("%lld",&w[i]);//站厅到地铁口 
	for(long long i=1; i<=n; i++)
	{
		scanf("%lld",&cnt[i]);
		for(long long j=1; j<=cnt[i]; j++)
			scanf("%lld%lld",&x,&y),a[i].push_back(x),t[i].push_back(y),d[x][++d[x][0]]=i,tim[x][d[x][0]]=y;//站台到站厅 
	}
	for(long long i=1; i<=n; i++)
		for(long long j=1; j<=n; j++)
			if(i!=j)
				dis[i][j]=INF;
	for(long long i=1; i<=n; i++)
		for(long long j=0; j<cnt[i]; j++)
			for(long long k=1; k<=d[a[i][j]][0]; k++)
				if(i!=d[a[i][j]][k])
					dis[i][d[a[i][j]][k]]=dis[d[a[i][j]][k]][i]=t[i][j]+tim[a[i][j]][k];
	for(long long k=1; k<=n; k++)
		for(long long i=1; i<=n; i++)
			for(long long j=1; j<=n; j++)
				if(i!=k && k!=j && i!=j && dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		dan=INF;
		for(long long i=1; i<=d[x][0]; i++)
			for(long long j=1; j<=d[y][0]; j++)
				if(tim[x][i]+tim[y][j]+dis[d[x][i]][d[y][j]]<dan)//哎呀董老大 
					dan=tim[x][i]+tim[y][j]+dis[d[x][i]][d[y][j]]; 
		dan+=w[x]+w[y];
		printf("%lld\n",dan); 
	}
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

改个long long 一次过小样例，有点shun了16:57
一次过7个样例，这真shun了样例7 1.399s 
不管了哈哈
哎呀董老师助我 
17:03

*/
