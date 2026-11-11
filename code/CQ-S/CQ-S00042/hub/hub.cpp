#include<bits/stdc++.h>
using namespace std;
namespace zzy{
	const int maxn=1e6+10;
	const int INF=0x3f3f3f3f;
	int cid,T,n,k,rt,px,py,mxlen;
	struct Edge{int v,next;}edge[maxn<<1];
	int head[maxn],tot;
	void add_edge(int u,int v){edge[++tot]={v,head[u]};head[u]=tot;}
	int fa[maxn];
	void find(int u,int d){
		if(d>=mxlen)px=u,mxlen=d;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if(v==fa[u])continue ;
			fa[v]=u;
			find(v,d+1);
		} 
	}
	int dep[maxn],mxd[maxn];
	int dfn[maxn],in[maxn],out[maxn],dfnid[maxn];
	void predfs1(int u){
		in[u]=dfn[u]=++dfn[0];dfnid[dfn[u]]=u;
		dep[u]=dep[fa[u]]+1;
		mxd[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if(v==fa[u])continue ;
			fa[v]=u;
			predfs1(v);
			mxd[u]=max(mxd[u],mxd[v]+1);
		}
		out[u]=dfn[0];
	}
	int cx[maxn],lenx;
	int cy[maxn],leny;
	int mid;
	int val[maxn];
	int f[maxn][20],g[maxn][20],h[maxn][20],Log[maxn];
	int prex[maxn],prey[maxn];
	void predfs2(int u){
		int mx=0,secmx=0;
		f[u][0]=fa[u];
		g[u][0]=val[u];
		h[u][0]=val[u]-dep[fa[u]];
		for(int i=1;i<=Log[dep[u]];i++){
			f[u][i]=f[f[u][i-1]][i-1];
			g[u][i]=max(g[u][i-1],g[f[u][i-1]][i-1]);
			h[u][i]=max(h[u][i-1],h[f[u][i-1]][i-1]);
		}
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if(v==fa[u])continue ;
			if(mxd[v]>=mxd[mx])secmx=mx,mx=v;
			else if(mxd[v]>=mxd[secmx])secmx=v;
		}
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if(v==fa[u])continue ;
			if(v==mx)val[v]=mxd[secmx]+1;
			else val[v]=mxd[mx]+1;
		}
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if(v==fa[u])continue ;
			predfs2(v);
		}
	}
	int sum[maxn],presum[maxn];
	int check(){
		for(int id=n;id>=1;id--){
			int u=dfnid[id];
			sum[u]=0;
			for(int i=head[u];i;i=edge[i].next){
				int v=edge[i].v;
				if(v==fa[u])continue ;
				sum[u]+=sum[v];
			}
			sum[u]+=(mxd[u]>=mid);
		}
		for(int i=1;i<=n;i++)presum[i]=0;
		for(int id=1;id<=n;id++){
			int u=dfnid[id];
			for(int i=head[u];i;i=edge[i].next){
				int v=edge[i].v;
				if(v==fa[u])continue ;
				presum[v]=presum[u]+sum[u]-sum[v];
			}
		}
		int ans=n;
		static int mncnt[maxn];
		for(int i=1;i<=n;i++)mncnt[i]=INF;
		for(int u=1;u<=n;u++){
			int p=u;
			for(int i=Log[dep[u]];i>=0;i--){
				if(!f[p][i])continue ;
				if(h[p][i]+dep[u]<=mid)p=f[p][i];
			}
			mncnt[p]=min(mncnt[p],sum[u]+(mxd[u]<mid));
		}
		for(int u=1;u<=n;u++){
			if(mncnt[u]==INF)continue ;
			int p=u;
			for(int i=Log[dep[u]];i>=0;i--){
				if(!f[p][i])continue ;
				if(g[p][i]<mid)p=f[p][i];
			}
			ans=min(ans,presum[p]+mncnt[p]);
		}
//		int mx=0;
//		for(int i=2;i<=lenx;i++){
//			mx=max(mx,val[cx[i]]);
//			if(mx>=mid)break ;
//			int p=
//		}
//		mx=0;
//		for(int i=2;i<=leny;i++){
//			mx=max(mx,val[cy[i]]);
//			if(mx>=mid)break ;
//		}
		return ans;
	}
	void clear(){
		lenx=leny=0;
		for(int i=1;i<=n;i++)head[i]=fa[i]=val[i]=0;
		dfn[0]=tot=0;
	}
	int main(){
		cin>>cid>>T;
		while(T--){
			clear();
			cin>>n>>k;
			for(int i=1,u,v;i<n;i++){
				cin>>u>>v;
				add_edge(u,v),add_edge(v,u);
			}
			px=py=mxlen=0;
			for(int i=1;i<=n;i++)fa[i]=0;
			find(1,0);
			swap(px,py);
			for(int i=1;i<=n;i++)fa[i]=0;
			find(py,0);
			rt=px;
			for(int i=1;i<=mxlen/2;i++)rt=fa[rt];
			mxd[0]=-1;
			for(int i=1;i<=n;i++)fa[i]=0;
			for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
			val[rt]=INF;
			predfs1(rt);predfs2(rt);
			int now=px;
			while(now)cx[++lenx]=now,now=fa[now];
			reverse(cx+1,cx+lenx+1);cx[lenx+1]=0;
			now=py;
			while(now)cy[++leny]=now,now=fa[now];
			reverse(cy+1,cy+leny+1);cy[leny+1]=0;
			
			for(int i=1;i<=lenx;i++)prex[i]=max(prex[i-1],val[cx[i+1]]+i-1);
			for(int i=1;i<=leny;i++)prey[i]=max(prey[i-1],val[cy[i+1]]+i-1);
			
			int l=0,r=n,ans=n;
			while(l<=r){
				mid=(l+r)>>1;
				if(check()<=k)ans=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<ans<<'\n';
		}

		return 0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}

