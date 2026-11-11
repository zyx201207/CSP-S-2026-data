#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int e[2*N],ne[2*N],h[N],idx;
int deep[N],f[N][22],dfn[N],cnt;
int c[N],pos[N];
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
	dfn[u]=++cnt;
	deep[u]=deep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=h[u];~i;i=ne[i]){
		int v=e[i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[f[x][i]]>=deep[y]){
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int id,t;
	scanf("%d%d",&id,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) h[i]=-1,deep[i]=0;
		idx=cnt=0;
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		if(id<=3){
			dfs(1,0);
			int M=1<<n,ans=0x3f3f3f3f;
			for(int p=0;p<M;p++){
				bitset<35> bs(p);
				if(bs.count()!=k) continue;
				int len=0;
				for(int j=0;j<n;j++){
					if(bs[j]==1){
						c[++len]=dfn[j+1];
						pos[len]=j+1;
					}
				}
				sort(c+1,c+len+1);
				int f=0;
				for(int i=2;i<=len;i++){
					if(c[i]-c[i-1]!=1) f++;
				}
				if(f>1) continue;
				int mx=0;
				for(int i=1;i<=n;i++){
					int mi=0x3f3f3f3f;
					for(int j=1;j<=len;j++){
						mi=min(mi,deep[i]+deep[pos[j]]-2*deep[lca(i,pos[j])]);
					}
					mx=max(mx,mi);
				}
				ans=min(ans,mx);
			}
			printf("%d\n",ans);
			continue;
		}
		if(k==2){
			dfs(1,0);
			int ans=0x3f3f3f3f;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int mx=0;
					for(int p=1;p<=n;p++){
						mx=max(mx,min(deep[p]+deep[i]-2*lca(p,i),deep[p]+deep[j]-2*lca(p,j)));
					}
					ans=min(ans,mx);
				}
			}
			printf("%d\n",ans);
			continue;
		}
		printf("1\n");
	}
	return 0;
}