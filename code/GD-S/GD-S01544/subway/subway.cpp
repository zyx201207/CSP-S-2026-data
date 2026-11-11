#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
const int N=505;
const int M=5e4+5;
int a[N][M],t[N][M];
int k[M];
int w[N];
struct edge
{
	int nxt,to,id;
}e[M<<1];
int minn;
int head[N],id_[M][N],cnt;
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].nxt=head[x];
	head[x]=cnt;
	e[cnt].to=y;
	e[cnt].id=z;
}
void dfs(int st,int ed,int step,int id)
{
//	cout << st << " " << ed << " " << step << "\n" ;
	if(st==ed) minn=min(minn,step);
	for(int i=head[st];i;i=e[i].nxt)
	{
//		if(e[i].to == 2) cout << " __________ " ;
		if(id==-1)
		{
			dfs(e[i].to,ed,step+t[e[i].id][st],e[i].id);
		}
		else
		{
			if(id==e[i].id)
			{
//				cout << id << " " << e[i].to << endl ;
				dfs(e[i].to,ed,step+t[id][e[i].to],id);
			}
			else
			{
//				cout << id << " " << st << " " << e[i].id << " " << e[i].to << endl ;
				dfs(e[i].to,ed,step+t[id][st]+t[e[i].id][e[i].to],e[i].id);
			} 
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(j!=1)
			{
				add(a[i][j-1],a[i][j],i);
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		minn=INT_MAX;
		dfs(x,y,w[x]+w[y],-1);
		printf("%d\n",minn);
	}
	return 0;
}
