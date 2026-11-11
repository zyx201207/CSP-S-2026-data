#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;

int c,T,ans=N,now=0;
int n,k;

int head[N],nxt[N*2],to[N*2],cnt;
int dist[N],f[N];
bool cho[N],vis[N];

void add(int u,int v){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}

void LCA(int x,int y){
	for(int i=1;i<=n;i++){
		
	}
}

void sea(int fa,int u){
	
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]&&cho[v]){
			sea(u,v);
		}
	}
}

void search(int fa,int u,int dep){
	
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		
		if(v!=fa){
			dist[v]=dist[u]+1;
			f[v]=u;
			search(u,v,dep+1);
		}
	}
}

void check(){
	
	int kuain=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(cho[i]&&!vis[i]){
			kuain++;
			sea(0,i);
		}
		if(kuain>2) return;
	}
	
	now=0;
	for(int i=1;i<=n;i++){
		if(cho[i]){
			memset(dist,0,sizeof(dist)); 
			search(0,i,0);
			for(int j=1;j<=n;j++){
				if(j!=i&&cho[j])now=max(now,dist[j]);
			}
		} 
	}
	ans=min(now,ans);
}

void dfs(int u,int num){
	
	if(num==k){
		check();
		return;
	}
	if(u>n) return;
	
	cho[u]=1;
	dfs(u+1,num+1);
	cho[u]=0;
	dfs(u+1,num);
	
}

void init(){
	cnt=0;
	memset(cho,0,sizeof(cho));
	memset(head,0,sizeof(head));
	memset(to,0,sizeof(to));
	memset(nxt,0,sizeof(nxt));
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		init();
		cin>>n>>k;
		for(int x,y,i=1;i<=n;i++){
			cin>>x>>y;
			add(x,y);add(y,x);
		}
		
		dfs(1,0);
		
		cout<<ans<<endl;
	}
	
	return 0;
} 
