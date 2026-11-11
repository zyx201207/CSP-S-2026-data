#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
template<typename T>void qr(T &x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int N=550,M=5e5+10;
vector<PII>G[M];
int d[N][N],testnum,n,m,maxrd,Q,out[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	qr(testnum);qr(n);qr(m);qr(maxrd);qr(Q);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++)qr(out[i]);
	for(int i=1,x,t,cnt;i<=n;i++)
	{
		qr(cnt);
		while(cnt--)
		{
			qr(x);qr(t);
			G[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<G[i].size();j++)
			for(int k=0;k<j;k++)
			{
				int x=G[i][j].first,y=G[i][k].first,w=G[i][j].second+G[i][k].second;
				d[x][y]=d[y][x]=min(d[x][y],w);
			}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(i!=k)for(int j=1;j<i;j++)if(j!=k)
		d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
	while(Q--)
	{
		int x,y;qr(x);qr(y);
		int res=1ll<<60;
		for(auto i:G[x])for(auto j:G[y])res=min(res,d[i.first][j.first]+i.second+j.second);
		printf("%lld\n",out[x]+out[y]+res);
	}
	return 0;
}
/*
空洞骑士真的很好玩



没有可以思考的心智

没有可以屈从的意志 

没有为苦难而哭泣的声音

生于神与虚空之手

你必将封印在众人梦中散布瘟疫的障目之光

你是容器

你是空洞骑士 



去年我就写了这些，真的会有人看到吗？ 
*/
