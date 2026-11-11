#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;

int n,k,depth[N],color[N],d[N],ans=1e9,f[N];
vector <int> adj[N];

void init(){
	ans=1e9;
	memset(depth,0,sizeof(depth));
	memset(color,0,sizeof(color));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) d[i]=1e9;
	for(int i=1;i<=n;i++) adj[i].clear();
}

void dfs1(int u,int fa){
	depth[u]=depth[fa]+1;
	f[u]=fa;
	for(int v:adj[u]){
		if(v==fa) continue;
		dfs1(v,u);
	}
}

void dfs2(int u,int fa,int mask,int t){
	color[u]=t;
	for(int v:adj[u]){
		if(v==fa) continue;
		if((mask>>(v-1))&1) dfs2(v,u,mask,t);
	}
}

int lca(int x,int y){
	if(depth[x]<depth[y]) swap(x,y);
	while(depth[x]>depth[y]) x=f[x];
	while(x!=y) {x=f[x];y=f[y];}
	return x;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--){
		scanf("%d %d",&n,&k);
		init();
		for(int i=1;i<=n-1;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs1(1,0);
		//if(T==0) printf("%d\n",lca(10,9));
		for(int mask=0;mask<(1<<n);mask++){
			int cnt=0;
			for(int i=0;i<n;i++) {
				if((mask>>i)&1) cnt++;
			}
			if(cnt!=k) continue;
			cnt=0;
			memset(color,0,sizeof(color));
			for(int i=1;i<=n;i++) d[i]=1e9;
			for(int i=0;i<n;i++){
				if(((mask>>i)&1)==0) continue;
				//cout<<mask<<" "<<i+1<<endl;
				if(color[i+1]) continue;
				cnt++;
				dfs2(i+1,i+1,mask,cnt); 
			} 
			if(cnt>2) continue;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(((mask>>(j-1))&1)==0) continue;
					d[i]=min(d[i],depth[i]+depth[j]-2*depth[lca(i,j)]);
				}
			}
			int res=0;
			for(int i=1;i<=n;i++) res=max(res,d[i]);
			//printf("%d %d\n",mask,res);
			ans=min(ans,res); 
		}
		printf("%d\n",ans);
	}
}
