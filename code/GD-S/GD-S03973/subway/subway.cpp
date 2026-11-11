#include<bits/stdc++.h>
using namespace std;
const int N=505,M=2e6+10;
int c,m,n,d,q,A[N],k,a,b;
long long B[N],ans;
long long dis[N][N],gr[N];
int head[N],cnt;
bool vis[N];
struct e
{
	int to,nxt;
	long long v;
}edge[M];
void adde(int fr,int to,long long v)
{
	cnt++;
	edge[cnt].nxt=head[fr];
	edge[cnt].v=v;
	edge[cnt].to=to;
	head[fr]=cnt;
}
struct node
{
	int id;
	long long dis;
	node(int b,long long c)
	{
		id=b;
		dis=c;
	}
	bool operator < (const node &a) const
	{
		return dis > a.dis;
	}
};
void dj(int x)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[x][i]=INT_MAX;
	queue<int> q;
	dis[x][x]=0;
	q.push(x);
	while(q.size())
	{
		int pos=q.front();
		q.pop();
		if(vis[pos])continue;
		vis[pos]=1;
		for(int i=head[pos];i;i=edge[i].nxt)
		{
			if(dis[x][edge[i].to]>dis[x][pos]+edge[i].v)
			{
				dis[x][edge[i].to]=dis[x][pos]+edge[i].v;
				q.push(edge[i].to);
				//cout<<pos<<"to"<<dis[x]
			}
		}
	}
	return ;
}
//--------------------
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&gr[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d%lld",&A[j],&B[j]);
		for(int ii=1;ii<k;ii++)
			for(int jj=ii+1;jj<=k;jj++)
			{
				adde(A[ii],A[jj],B[ii]+B[jj]);
				adde(A[jj],A[ii],B[ii]+B[jj]);
			}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>b)
			swap(a,b);
		if(dis[a][b]==0)
			dj(a);
		ans=dis[a][b]+gr[a]+gr[b];
		printf("%lld\n",ans); 
	}/*
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":";
		for(int j=1;j<=n;j++)
			cout<<dis[i][j]<<" ";
		cout<<endl;
	}/*
	for(int i=1;i<=cnt;i++)	
		cout<<i<<" "<<edge[i].to<<" "<<edge[i].v<<" "<<edge[i].nxt<<endl;*/
	return 0;
} 
