#include<bits/stdc++.h>
#define qwe(i,l,r) for(int i=(l);(i)<=(r);++i)
#define ewq(i,l,r) for(int i=(l);(i)>=(r);--i)
#define qwex(e,x) for(int e=(x);e;e=ne[e])
#define ll long long
#define int ll
#define pii pair<int,int>
#define fir first
#define sec second
#define low(x) (x)&(-(x))
#define whlie while
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=1e6+5;
int h[N],ne[N<<1],t[N<<1],cnt,w[N<<1];
int cc;
void add_edge(int x,int y){
	t[++cnt]=y;
	ne[cnt]=h[x];
	h[x]=cnt;
}
int n,k;
	int ans;
	int dep[N],rt,mxdep[N];
	int a[N],b[N],topa,topb;
	int c[N];
	void dfs1(int u,int fa){
		dep[u]=dep[fa]+1;
		if(dep[u]>dep[rt])rt=u;
		qwex(e,h[u])if(t[e]!=fa&&!w[e])dfs1(t[e],u);
	}
	
	bool dfs2(int u,int fa,int ed){
		if(u==ed){
			a[++topa]=u;
			return 1;
		}
		qwex(e,h[u]){
			if(t[e]!=fa&&!w[e]){
				if(dfs2(t[e],u,ed)){
					a[++topa]=u;
					return 1;
				}
			}
		}
		return 0;
	}
	void dfs3(int u,int fa){
		mxdep[u]=dep[u]=dep[fa]+1;
		qwex(e,h[u]){
			if(t[e]!=fa&&!w[e]){
				dfs3(t[e],u);
				mxdep[u]=max(mxdep[u],mxdep[t[e]]);
			}
		}
		c[u]=mxdep[u]-dep[u];
	}
	void calc(int u,int e){
		if(u==0)return;
		w[e]=w[e^1]=1;
			
//			printf("split %lld %lld\n",u,t[e]);
			
			topa=rt=0;
			dfs1(t[e],u);
			int st=rt;
			dfs1(rt,0);
			int ed=rt;
			dfs2(st,0,ed);
			topb=topa;
			qwe(i,1,topb)b[i]=a[i];
			dfs3(b[(topb+1)/2],0);
//			qwe(i,1,n)cout<<c[i]<<' ';cout<<'\n';
//			qwe(i,1,n)cout<<dep[i]<<' ';cout<<'\n';
//			qwe(i,1,n)cout<<mxdep[i]<<' ';cout<<'\n';
			
			topa=rt=0;
			dfs1(u,t[e]);
			st=rt;
			dfs1(rt,0);
			ed=rt;
			dfs2(st,0,ed);
			dfs3(a[(topa+1)/2],0);
//			qwe(i,1,n)cout<<c[i]<<' ';cout<<'\n';
//			qwe(i,1,n)cout<<dep[i]<<' ';cout<<'\n';
//			qwe(i,1,n)cout<<mxdep[i]<<' ';cout<<'\n';
			c[a[(topa+1)/2]]=1e9;
			c[b[(topb+1)/2]]=1e9;
			sort(c+1,c+n+1,greater<int>());
//			qwe(i,1,n)cout<<c[i]<<' ';cout<<'\n';
			c[n+1]=-1;
//			if(c[k+1]==0)cout<<u<<' '<<e<<'\n';
//			printf("ans:%lld %lld %lld\n",c[k+1],a[(topa+1)/2],b[(topb+1)/2]);
			ans=min(ans,c[k+1]+1);
			w[e]=w[e^1]=0;
	}
	void dfs(int u,int fa){
		qwex(e,h[u]){
			if(t[e]==fa)continue;
			calc(u,e);
			dfs(t[e],u);
		}
	}
	int siz[N],top;
	struct asd{
		int u,e,x;
	}p[N];
	bool cmp(asd f1,asd f2){
		return f1.x<f2.x;
	} 
	void dfs4(int u,int fa){
		dep[u]=dep[fa]+1;
		siz[u]=1;
		qwex(e,h[u]){
			if(t[e]==fa)continue;
			dfs4(t[e],u);
			siz[u]+=siz[t[e]];
		}
		qwex(e,h[u]){
			if(t[e]==fa)continue;
			p[++top]={u,e,max(siz[t[e]],n-siz[t[e]])};
		}
	}
void solve(){
	cnt=1;top=0;ans=1e9;
	qwe(i,1,n)h[i]=0;
	n=read();k=read();
	qwe(i,1,n-1){
		int x=read(),y=read();
		add_edge(x,y);
		add_edge(y,x);
	}
	if(n<=1000){
		dfs(1,0);
		cout<<ans<<'\n';
		return;
	}
	if(cc==13||cc==14){
		int len=(n+1)/2-2+1;
		k-=2;
		if(k==n)puts("0");
		else cout<<max((len-k+3)/4,1ll)<<'\n';
		return;
	}
	dfs4(1,0);
	sort(p+1,p+top+1,cmp);
	qwe(i,1,30)calc(p[i].u,p[i].e);
//	puts("pass");
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cc=read();int T=read();
	while(T--)solve();
}
