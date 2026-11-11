#include<bits/stdc++.h>
#define T_T return 0
using namespace std;
long long c,n,m,d,Q;
long long T[500010];
long long T2[500*20000+10];
struct Node{
	long long to,w,next;
}edge[1000010];
long long head[1000010],cnt;
long long k[510];
struct F{
	long long a,t;
};
F z[510][20010];
F bj[20010][510];
long long Cnt[500010];
void add(long long u,long long v,long long w)
{
	edge[cnt]={v,w,head[u]};
	head[u]=cnt++;
}
long long dist[500010],up[500010][20],dep[500010];
void dfs(long long u,long long p,long long d)
{
	dist[u]=d;
	up[u][0]=1;
	for(int i=1;i<=19;i++) up[u][i]=up[up[u][i-1]][i-1];
	for(int i=head[u];~i;i=edge[i].next)
	{
		long long v=edge[i].to,z=edge[i].w;
		if(v==p) continue;
		dep[v]=dep[u]+1;
		dfs(v,u,d+z);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(head,-1,sizeof head);
	memset(dist,0x3f,sizeof dist);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>T[i];
	T[0]=T[m];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) 
		{
			cin>>z[i][j].a>>z[i][j].t;
			z[i][j].a=z[i][j].a+(i-1)*m;
			T2[z[i][j].a]=z[i][j].t;
			bj[z[i][j].a%m][++Cnt[z[i][j].a%m]]={z[i][j].a,z[i][j].t};
		}
		for(int j=1;j<k[i];j++) add(z[i][j].a,z[i][j+1].a,0);
	}
	for(int i=0;i<=m;i++)
	{
		if(Cnt[i]>=2)
		{
			for(int j=1;j<=Cnt[i];j++)
			{
				for(int k=j+1;k<=Cnt[i];k++) 
				{
					add(bj[i][j].a,bj[i][k].a,bj[i][j].t+bj[i][k].t);
					add(bj[i][k].a,bj[i][j].a,bj[i][k].t+bj[i][j].t);
				}
			}
		}
	}
	dfs(1,1,0);
	for(int i=1;i<=Q;i++)
	{
		long long x,y;
		long long ans=LONG_LONG_MAX;
		cin>>x>>y;
		for(int i=x;i<=n*m;i=i+m)
		{
			for(int j=y;j<=n*m;j=j+m) 
			{
				if(dist[i]<0x3ffffff/2&&dist[j]<0x3ffffff/2) ans=min(ans,max(dist[j],dist[i])-min(dist[i],dist[j])+T2[i]+T2[j]+T[i%m]+T[j%m]);
			}
		}
		cout<<ans<<endl;
	}
	T_T;
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
*/
