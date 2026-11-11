#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
const int N=1e5+5;
int c,T,n,k,cnt_e,ehead[N],ff[N],dep[N],fa[N][25],ans;
int findfa(int x){return ff[x]==x?x:ff[x]=findfa(ff[x]);}
void mg(int x,int y)
{
	int fx=findfa(x),fy=findfa(y);
	if(fx==fy)return;
	ff[fx]=fy;
	return;
}
struct E{
	int to,pre;
}e[N<<1];
void adde(int from,int to)
{
	e[++cnt_e].to=to;
	e[cnt_e].pre=ehead[from];ehead[from]=cnt_e;
	return;
}
void init()
{
	for(int i=1;i<=n;++i)ehead[i]=0;
	cnt_e=0;ans=n+5;
	return;
}
int cc(int x)
{
	int s=0;
	while(x)
	{
		if(x&1)++s;
		x>>=1;
	}return s;
}
void dfs(int u,int uf)
{
	dep[u]=dep[uf]+1;fa[u][0]=uf;
	for(int i=1;i<=20;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=ehead[u];i;i=e[i].pre)
	{
		int v=e[i].to;if(v==uf)continue;
		dfs(v,u);
	}
	return;
}
int getlca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;--i)
		if(dep[u]-(1<<i)>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;--i){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];v=fa[v][i];}}
	return fa[u][0];
}
int getdis(int u,int v)
{
	int lca=getlca(u,v);
	return dep[u]+dep[v]-2*dep[lca];
}
bool chk(int ss)
{
	for(int i=1;i<=n;++i)ff[i]=i;
	for(int i=1;i<=n;++i)
	{
		if(!((ss>>(i-1))&1))continue;
		for(int j=ehead[i];j;j=e[j].pre)
		{
			int v=e[j].to;
			if((ss>>(v-1))&1)
				mg(i,v);
		}
	}int c=0;
	for(int i=1;i<=n;++i)
	{
		if(!((ss>>(i-1))&1))continue;
		if(findfa(i)==i)++c;
	}return (c==1||c==2);
}
int calc(int ss)
{
	int mx=0;
	for(int i=1,mn;i<=n;++i)
	{
		if((ss>>(i-1))&1)continue;
		mn=n+5;
		for(int j=1;j<=n;++j)
		{
			if(!((ss>>(j-1))&1))continue;
			mn=min(mn,getdis(i,j));
		}
		mx=max(mx,mn);
	}return mx;
}
void Main()
{
	cin>>n>>k;init();
	for(int i=1,u,v;i<n;++i)
	{
		cin>>u>>v;
		adde(u,v);adde(v,u);
	}dfs(1,0);
	for(int i=0;i<(1<<n);++i)
	{
		if(cc(i)!=k)continue;
		if(!chk(i))continue;
		ans=min(ans,calc(i));
	}cout<<ans<<'\n'; 
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--)Main();
	return 0;
}
/*
14:50 过了T1的所有大样例。好了 。心态++。去把所有题面看了一遍

14:56 T2题面有点 看不懂 ，不过不急

14:58 感觉T3更简单呢，干T3吧

15:10 T3 敲了个n^2的dp，24pts 目前分数：100+0+24+0=124

15:23 看懂了T3题面，开打

15:42 差不多把T3暴力打掉了，准备去上个厕所

15:53 拼完了 T3 剩下的东西，可以拿44分了。目前分数：100+44+24+0=168。吃个巧克力

16:03 写了T1的拍子

16:35 T4 15分拿下。目前 100+44+24+15=183pts

16:43 发现 T2 的代码跑sample5也就十几秒，所以分数可能高于183/se [183,199]
*/
