#include<cstdio>
#include<algorithm>
#define N 1000005
using namespace std;

using ll=long long;
ll read() {
	ll x=0,t=1; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') t=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*t;
}
int T,n,k,m,t,d[N],h[N],f[N];
int tot,head[N],nxt[N*2],ver[N*2];
int dep[N],pre[N];
bool on[N];
void insert(int x,int y) {
	ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}
void dfs1(int x,int fa,int &mx,int &p) {
	if(dep[x]>mx) mx=dep[x],p=x;
	for(int i=head[x],y;i;i=nxt[i]) {
		if((y=ver[i])!=fa) dep[y]=dep[x]+1,pre[y]=x,dfs1(y,x,mx,p);
	}
}
void dfs2(int x,int fa) {
	f[x]=1,h[x]=0;
	for(int i=head[x],y;i;i=nxt[i]) {
		if((y=ver[i])==fa) continue;
		dfs2(y,x),h[x]=max(h[x],h[y]+1);
		if(h[y]>=t) f[x]+=f[y];
	}
}
int dp[N];
void dfs3(int x,int fa,int l) {
	dp[x]=n+1;
	if(l>t) return;
	int son=0;
	for(int i=head[x],y;i;i=nxt[i]) {
		if((y=ver[i])==fa) continue;
		if(h[y]>=h[son]) son=y;
	}
	int mx=0;
	for(int i=head[x],y;i;i=nxt[i]) {
		if((y=ver[i])!=fa&&y!=son) mx=max(mx,h[y]+1);
	}
	if(mx>t) return;
	dp[x]=f[x];
	if(son!=0) {
		dfs3(son,x,max(l,mx)+1);
		dp[x]=min(dp[x],dp[son]);
	}
}
int g[N],sum[N],L[N],R[N];
int lt,rt,q[N];
int check(int root,int _) {
	t=_; int ans=n;
	dfs2(root,0);
	int l=t+1,r=m-t; sum[l-1]=0;
	for(int i=l;i<=r;i++) {
		int x=d[i],cur=1; g[i]=0;
		for(int j=head[x],y;j;j=nxt[j]) if(!on[y=ver[j]]) {
			g[i]=max(g[i],h[y]+1);
			if(h[y]>=t) cur+=f[y];
		}
		sum[i]=sum[i-1]+cur;
	}
	L[l]=l,R[r]=r;
	for(int i=l+1;i<r;i++) {
		L[i]=max(L[i-1],i-max(t-g[i],0));
	}
	for(int i=r-1;i>l;i--) {
		R[i]=min(R[i+1],i+max(t-g[i],0));
	}
//	lt=1,rt=0; q[0]=l;
	for(int i=l+1;i<r;i++) {
		ans=min(ans,sum[L[i]]-sum[l-1]+sum[r]-sum[R[i]-1]);
		if(i+1<r) {
			ans=min(ans,sum[L[i]]-sum[l-1]+sum[r]-sum[R[i+1]-1]);
		}
//		while(lt<=rt&&g[i]>=g[q[rt]]+i-q[rt]) rt--;
//		q[++rt]=i;
//		while(lt<=rt&&g[q[lt]]+i-q[lt]>t) lt++;
//		ans=min(ans,sum[q[lt-1]]-sum[l-1]+sum[r]-sum[i]);
	}
//	if(t==0) fprintf(stderr,"%d %d %d\n",l,r,ans);
	int mn=0;
	for(int i=l;i<=r;i++) {
		int x=d[i];
		for(int j=head[x],y;j;j=nxt[j]) if(!on[y=ver[j]]) {
			dfs3(y,x,0);
			mn=min(mn,dp[y]-f[y]);
		}
	}
	ans=min(ans,sum[r]-sum[l-1]+mn);
	return ans;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(),T=read();
	while(T--) {
		tot=0;
		for(int i=1;i<=n;i++) head[i]=on[i]=0;
		n=read(),k=read();
		for(int i=1,x,y;i<n;i++) {
			scanf("%d%d",&x,&y),insert(x,y),insert(y,x);
		}
		int mx1=-1,p=0; dep[1]=0,dfs1(1,0,mx1,p);
		int mx2=-1,q=0; dep[p]=0,dfs1(p,0,mx2,q);
		m=0;
		for(int x=q;x!=p;x=pre[x]) d[++m]=x;
		d[++m]=p;
		for(int i=1;i<=m;i++) on[d[i]]=1;
		int l=0,r=m/2;
		while(l<r) {
			int mid=(l+r)>>1;
			if(check(p,mid)<=k) r=mid; else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}

/*
check if <vector> <cmath> is open

check multitest

二分答案 t
拎出直径，剩下的没时间写了 

18:27
*/
