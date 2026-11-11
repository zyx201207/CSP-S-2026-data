#include<bits/stdc++.h>
using namespace std;
const int M=1000010,N=20,K=2;
int c,tst,n,k,x,y,h[M],cnt,deg[M],d[M],f[M][N],rt,stk[M],tp,l,r,mid,ans;
int p[K],s[K][M],sz[K],lc[K],nd[K],id,dfn[M],tot;bool vis[M];
struct node{int to,nxt;}e[M<<1];
void add(int x,int y)
{
	e[++cnt]=(node){y,h[x]},
	h[x]=cnt;
}
void dfs(int x,int l)
{
	d[x]=d[l]+1,f[x][0]=l,dfn[x]=++tot;
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=l)dfs(e[i].to,x);
}
int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	for(int i=N-1;i>=0;--i)if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y)return x;
	for(int i=N-1;i>=0;--i)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0]; 
}
int jmp(int x,int dis)
{
	while(dis)x=f[x][__builtin_ctz(dis)],dis&=(dis-1);
	return x;
}
int calc(int x,int y,int l,int dis)
{
	if(d[y]-d[l]>=dis)return jmp(y,dis);
	else return jmp(x,d[x]-d[l]-(dis-(d[y]-d[l])));
}
int cmp(int x,int y){return dfn[x]<dfn[y];}
int calcdis(int x,int y){return d[x]+d[y]-2*d[lca(x,y)];}
int pd(int dis)
{
	if(dis*2>=(tp-1))return 1;
	p[0]=stk[dis+1],p[1]=stk[tp-dis];
	s[0][sz[0]=1]=p[0],s[1][sz[1]=1]=p[1];
	for(int i=1;i<=n;++i)
	{
		lc[0]=lca(p[0],i),nd[0]=d[i]+d[p[0]]-d[lc[0]]*2;
		lc[1]=lca(p[1],i),nd[1]=d[i]+d[p[1]]-d[lc[1]]*2;
		if(nd[0]>nd[1])id=1;
		else id=0; 
		if(nd[id]<=dis)continue;
		s[id][++sz[id]]=calc(p[id],i,lc[id],dis);
	}
	int now=0,fl=1;
	sort(s[0]+1,s[0]+sz[0]+1,cmp);
	s[0][0]=s[0][sz[0]];
	for(int i=1;i<=sz[0];++i)
	{
		now+=calcdis(s[0][i],s[0][i-1]);
		if((now>>1)+2>k){fl=0;break;}
	}
	sort(s[1]+1,s[1]+sz[1]+1,cmp);
	s[1][0]=s[1][sz[1]];
	for(int i=1;i<=sz[1];++i)
	{
		now+=calcdis(s[1][i],s[1][i-1]);
		if((now>>1)+2>k){fl=0;break;}
	}
	if(fl)return 1;
	p[0]=stk[dis+1],p[1]=stk[tp-dis];
	s[0][sz[0]=1]=p[0],s[1][sz[1]=1]=p[1];
	for(int i=1;i<=n;++i)
	{
		lc[0]=lca(p[0],i),nd[0]=d[i]+d[p[0]]-d[lc[0]]*2;
		lc[1]=lca(p[1],i),nd[1]=d[i]+d[p[1]]-d[lc[1]]*2;
		if(nd[0]>=nd[1])id=1;
		else id=0; 
		if(nd[id]<=dis)continue;
		s[id][++sz[id]]=calc(p[id],i,lc[id],dis);
	}
	now=0;
	sort(s[0]+1,s[0]+sz[0]+1,cmp);
	s[0][0]=s[0][sz[0]];
	for(int i=1;i<=sz[0];++i)
	{
		now+=calcdis(s[0][i],s[0][i-1]);
		if((now>>1)+2>k)return 0;
	}
	sort(s[1]+1,s[1]+sz[1]+1,cmp);
	s[1][0]=s[1][sz[1]];
	for(int i=1;i<=sz[1];++i)
	{
		now+=calcdis(s[1][i],s[1][i-1]);
		if((now>>1)+2>k)return 0;
	}
//	if(dis==1)
//	{
//		cout<<"!\n";
//		cout<<sz[0]<<' '<<sz[1]<<' '<<(now>>1)+2<<'\n';
//	}
	return 1;
}
void dfsc(int x)
{
	vis[x]=0;
	for(int i=h[x];i;i=e[i].nxt)
		if(vis[e[i].to])dfsc(e[i].to); 
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>tst;
	while(tst--)
	{
		cin>>n>>k;
		cnt=0;
		for(int i=1;i<=n;++i)h[i]=0;
		for(int i=1;i<=n;++i)deg[i]=0;
		for(int i=1;i<n;++i)
		{
			cin>>x>>y,add(x,y),add(y,x);
			++deg[x],++deg[y];
		}
		tot=0;
		dfs(1,0);
		rt=1; 
		for(int i=2;i<=n;++i)if(d[rt]<d[i])rt=i;
		tot=0;
		dfs(rt,0);
		x=1;
		for(int i=2;i<=n;++i)if(d[x]<d[i])x=i;
		tp=0;
		while(x!=rt)stk[++tp]=x,x=f[x][0];
		stk[++tp]=rt;
		for(int j=1;j<N;++j)
			for(int i=1;i<=n;++i)
				f[i][j]=f[f[i][j-1]][j-1];
		if(c&&c<=3)
		{
			ans=n-1;
			int mx=(1<<n)-1;
			for(int i=3;i<=mx;++i)
			{
				if(__builtin_popcount(i)!=k)continue;
				int ss=0,md=0,nd;
				for(int j=1;j<=n;++j)vis[j]=((i>>(j-1))&1);
				for(int j=1;j<=n;++j)
					if(!vis[j])
					{
						nd=n;
						for(int nj=1;nj<=n;++nj)if(vis[nj])nd=min(nd,calcdis(j,nj));
						md=max(md,nd);
					}
				if(md>=ans)continue;
				for(int j=1;j<=n;++j)
					if(vis[j])++ss,dfsc(j);
				if(ss>2)continue;
				ans=md;
			}
			cout<<ans<<'\n';
			continue;
		}
		l=0,r=(tp>>1);
//		cout<<"!"<<l<<' '<<r<<'\n';
		while(l<=r)
		{
			mid=(l+r)>>1; 
			if(pd(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
