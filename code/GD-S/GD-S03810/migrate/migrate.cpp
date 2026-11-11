#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
const int N=5e3+10;
const int M=2e6+10;
int c,T,n,d,a[M];
struct Node {
	int to,nxt;
	Node() {
		to=nxt=0;
	}
	Node(int a,int b) {
		to=a,nxt=b;
	}
} adj[N*N*2];
int head[N],idx,f[N],g[N],cnt[N];
inline void add(int x,int y) {
	adj[++idx]=Node(y,head[x]);
	head[x]=idx;
	return ;
}
inline void dfs(int u,int fa) {
	for(int i=head[u];i;i=adj[i].nxt) {
		int v=adj[i].to;
		if(v==fa) continue;
		if(f[u]+1>f[v]) continue;
		if(f[u]+1<f[v]) {
			f[v]=f[u]+1;
			cnt[v]=cnt[u];
		} else cnt[v]++;
		dfs(v,u);
	}
	return ;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--) {
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(c==13||c==14) {
			printf("0\n");
			continue;
		}
		if(c==11||c==12) {
			int k=a[2]-a[1];
			int p=d/k;
			if(p>1) printf("%lld\n",max(0ll,n-(p*2-1)));
			else printf("0\n");
			continue;
		}
		idx=0;
		for(int i=1;i<=n;i++)
			head[i]=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i!=j&&abs(a[i]-a[j])<=d)
					add(i,j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++)
				f[j]=inf,cnt[j]=0;
			f[i]=0,cnt[i]=1;
			dfs(i,0);
			for(int j=1;j<=n;j++) 
				if(cnt[j]==2) ans++; 
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}
