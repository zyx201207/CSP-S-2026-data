#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;
const int qwq=500010;
vector<int>e[qwq];
int to[qwq],head[qwq],nxt[qwq],tot;
void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int dfs(int u,int fa)
{
	long long mx=0,se=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa) continue;
		int x=dfs(v,u);
		if(x>=mx) se=mx,mx=x;
		else if(x>=se) se=x;
	}
	if(fa==-1) return mx+se+1;
	else       return mx+1;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==13||c==14)
	{
		while(t--)
		{
			scanf("%d%d",&n,&k);
			for(int x,y,i=1;i<=n-1;i++) scanf("%d%d",&x,&y);
			printf("%lld\n",1ll*((n+1)/2-k/2*2+2)/4+1);
		}
	}
	else
	{
		while(t--)
		{
			scanf("%d%d",&n,&k);
			for(int x,y,i=1;i<=n-1;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
//			printf("%lld\n",dfs(1,-1));
			printf("%lld",1ll*(dfs(1,-1)-k/2*2)/4+1);
			
		}
	}
	return 0;
}

