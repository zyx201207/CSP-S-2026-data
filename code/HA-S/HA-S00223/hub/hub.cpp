#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (long long)(1e18)

int n;

inline int read(){
	int t=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9') f=(c=='-')?(-1):(f),c=getchar();
	while(c>='0'&&c<='9') t=(t<<3)+(t<<1)+(c^48),c=getchar();
	return t*f;
}

const int N=1e3+10;

int ce,k,idx;
int head[N],nxt[N<<1],ver[N<<1];

void add(int u,int v){
	nxt[++idx]=head[u];
	head[u]=idx;
	ver[idx]=v;
}

bool vis[N],mk[N];

void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		if(mk[ver[i]]&&!vis[ver[i]]) dfs(ver[i]);
	}
}

int dis[N];

void solve(){
	n=read(),k=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	int ans=n+1;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k) continue;
		for(int j=1;j<=n;j++) if((i>>j-1)&1) mk[j]=true;
		int res=0;
		for(int j=1;j<=n;j++) if(!vis[j]&&mk[j]) res++,dfs(j);
		if(res==2){
			queue<int> q;
			for(int j=1;j<=n;j++)
				if(!mk[j]) dis[j]=n+1;
				else dis[j]=0,q.push(j);
			while(!q.empty()){
				int x=q.front();q.pop();
				for(int j=head[x];j;j=nxt[j]){
					int dao=ver[j];
					if(dis[dao]>dis[x]+1){
						dis[dao]=dis[x]+1;
						q.push(dao);
					}
				}
			}
			int Res=0;
			for(int j=1;j<=n;j++) Res=max(Res,dis[j]);
			ans=min(ans,Res);
		}
		for(int j=1;j<=n;j++) vis[j]=mk[j]=0;
	}
	cout<<ans<<"\n";
	idx=0;
	for(int i=1;i<=n;i++) head[i]=0;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ce=read();
	int T=read();
	while(T--) solve();
	return 0;
}

