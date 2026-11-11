#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5,M=5e5+5,INF=INT_MAX;

int head[N],nxt[M*2],to[M*2],wei[M*2],cnt;
bool vis[N];

int c,n,m,d,q,ans,now;
int w[N],a[N],t[N];

void add(int u,int v,int wi){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	wei[cnt]=wi;
	head[u]=cnt;
}

void dfs(int fa,int u,int goal){
	
	if(u==goal){
		ans=min(ans,now);
		return ;
	}
	
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i],we=wei[i];
		
		vis[u]=1;now+=we;
		if(!vis[v]) dfs(u,v,goal);
		vis[u]=0;now-=we;
	}
	
}

void work(int xx,int yy){
	ans=INF;
	
	memset(vis,0,sizeof(vis));
	dfs(0,xx,yy);
	
	cout<<ans+w[xx]+w[yy]<<endl;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int k,i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int r=j-1;r>=1;r--){
				add(a[r],a[j],t[r]+t[j]);
				add(a[j],a[r],t[r]+t[j]);
			}
		}
	}
	
	for(int x,y,i=1;i<=q;i++){
		cin>>x>>y;
		work(x,y); 
	}
	
	return 0;
} 
