#include<bits/stdc++.h>
using namespace std;
int n,k;
int hd[1000010],ne[2000010],to[2000010],tot;
void clear(){
	for(int i=1;i<=n;i++)
		hd[i]=0;
	tot=0;
}
void add(int x,int y){
	tot+=1;
	ne[tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
}
int fa[1000010],dis[1000010];
bool g[15][15],bj[1000010];
queue<int> q;
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
inline void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	fa[y]=x;
}
void solve1(){
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			g[i][j]=false;
	}
	for(int x=1;x<=n;x++)
	{
		for(int i=hd[x];i>=1;i=ne[i])
			g[x][to[i]]=g[to[i]][x]=true;
	}
	int ans=0x3f3f3f3f;
	for(int st=1;st<=(1<<n)-1;st++)
	{
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(st&(1<<(i-1)))
			{
				bj[i]=true;
				fa[i]=i;
				s+=1;
			}
			else bj[i]=false;
		}
		if(s>k)continue;
		for(int i=1;i<=n;i++)
		{
			if(!bj[i])continue;
			for(int j=i+1;j<=n;j++)
			{
				if(!bj[j]||!g[i][j])continue;
				merge(i,j);
			}
		}
		s=0;
		for(int i=1;i<=n;i++)
			if(bj[i]&&fa[i]==i)s+=1;
		if(s>2)continue;
		for(int i=1;i<=n;i++)
		{
			if(bj[i])
			{
				dis[i]=0;
				q.push(i);
			}
			else dis[i]=0x3f3f3f3f;
		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=hd[x];i>=1;i=ne[i])
			{
				if(dis[to[i]]==0x3f3f3f3f)q.push(to[i]);
				dis[to[i]]=min(dis[to[i]],dis[x]+1);
			}
		}
		int ts=0;
		for(int i=1;i<=n;i++)
			ts=max(ts,dis[i]);
		ans=min(ans,ts);
	}
	printf("%d\n",ans);
}
int dx,dy,dp[1000010],dp2[1000010];
void dfs2(int x){
	if(dp[x]>dp[dy])dy=x;
	for(int i=hd[x];i>=1;i=ne[i])
	{
		if(to[i]==fa[x])continue;
		fa[to[i]]=x;
		dp[to[i]]=dp[x]+1;
		dfs2(to[i]);
	}
}
void dfs22(int x,int fa){
	for(int i=hd[x];i>=1;i=ne[i])
	{
		if(to[i]==fa)continue;
		dp2[to[i]]=dp2[x]+1;
		dfs22(to[i],x);
	}
}
bool check2(int lim){
	fa[1]=0;
	dp[1]=0;
	dfs2(1);
	dx=dy;
	fa[dx]=0;
	dp[dx]=0;
	dfs2(dx);
	if(dp[dy]<=lim)return true;
	int tx=dy;
	for(int i=1;i<=lim;i++)
		tx=fa[tx];
	fa[tx]=0;
	dis[tx]=0;
	dfs2(tx);
	for(int i=1;i<=n;i++)
		bj[i]=false;
	for(int i=1;i<=n;i++)
	{
		dp2[i]=0;
		dfs22(i,0);
		bool tf=true;
		for(int j=1;j<=n&&tf;j++)
			if(dp[j]>lim&&dp2[j]>lim)tf=false;
		if(tf)return true;
	}
	return false;
}
void solve2(){
	int l=0,r=n;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check2(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r-1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		clear();
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		if(n==k)
		{
			printf("%d\n",0);
			continue;
		}
		if(n==k-1)
		{
			printf("%d\n",1);
			continue;
		}
		if(n<=10)
		{
			solve1();
			continue;
		}
		if(k==2)
		{
			solve2();
			continue;
		}
	}
	return 0;
}
