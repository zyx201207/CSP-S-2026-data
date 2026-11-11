#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;

struct Edge{
	int to;
	int ne;
}gr[N << 1];//
int hd[N],amo;//
void add_e(int u,int v)
{
	amo++;
	gr[amo] = {v,hd[u]};
	hd[u] = amo;
	return;
}
int dis[N][N];//
void DFS(int rt,int id,int fa)
{
	for(int i = hd[id];i;i = gr[i].ne)
	{
		int to = gr[i].to;
		if(to == fa)
			continue;
		dis[rt][to] = dis[rt][id] + 1;
		DFS(rt,to,id);
	}
	return;
}
Edge store[N];//
int n,k;//
int fa[N];//
int P[N];//
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void func(void)
{
	amo = 0;
	memset(hd,0x0,sizeof hd);
	scanf("%d%d",&n,&k);
	memset(P,0x0,sizeof P);
	for(int i = 1;i <= k;i++)
		P[i] = 1;
	reverse(P + 1,P + n + 1);
	for(int i = 1;i < n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_e(u,v),add_e(v,u);
		store[i] = {u,v};
	}
	memset(dis,0x0,sizeof dis);
	for(int i = 1;i <= n;i++)
		DFS(i,i,0);
	int ans = n;
	do{
		for(int i = 1;i <= n;i++)
			fa[i] = i;
		int com = k;
		for(int i = 1;i < n;i++)
		{
			int u = store[i].to,v = store[i].ne;
			if(P[u] && P[v])
			{
				int fx = find(u),fy = find(v);
				if(fx != fy)
				{
					com--;
					fa[fx] = fy;
				}
			}
		}
		if(com <= 2)
		{
			int res = 0;
			for(int i = 1;i <= n;i++)
			{
				int tdis = n;
				for(int j = 1;j <= n;j++)
					if(P[j])
						tdis = min(tdis,dis[i][j]);
				res = max(res,tdis);
			}
			ans = min(ans,res);
		}
	}while(next_permutation(P + 1,P + n + 1));
	printf("%d\n",ans);
	return;
}
int main(void)
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int casetype,T;
	scanf("%d%d",&casetype,&T);
	while(T--)
		func();
	return 0;
}
