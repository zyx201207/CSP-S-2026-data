#include<bits/stdc++.h>
using namespace std;
int C,T,n,p,ans=1e9;
int f[20005],d[20005],dis[20005];
int head[20005],nxt[40005],to[40005],cnt;
bool vis[20005],bz[20005];
inline void add(int u,int v){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
inline int root(int x){
	if(f[x]!=x) f[x]=root(f[x]);
	return f[x];
}
inline void chs(int k,int t){
	if(n-k+1<p-t) return;
	if(k>n){
		if(t<p) return;
		for(int i=1;i<=n;i++) f[i]=i,bz[i]=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			for(int j=head[i];~j;j=nxt[j]){
				int v=to[j];
				if(!vis[v]) continue;
				if(root(i)!=root(v)){
					f[root(i)]=root(v);
				}
			}
		}
		int c=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			if(!bz[root(i)]){
				bz[root(i)]=1;
				c++;
			}
		}
		if(c<=2){
			int h=0,t=0;
			memset(dis,0x7f,sizeof(dis));
			for(int i=1;i<=n;i++){
				if(!vis[i]) continue;
				d[++t]=i;
				dis[i]=0;
			}
			while(h<t){
				h++;
				int u=d[h];
				for(int i=head[u];~i;i=nxt[i]){
					int v=to[i];
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						d[++t]=v;
					}
				}
			}
			int max1=0;
			for(int i=1;i<=n;i++){
				max1=max(max1,dis[i]);
			}
			ans=min(ans,max1);
		}
		return;
	}
	if(t<p){
		vis[k]=1;
		chs(k+1,t+1);
	}
	vis[k]=0;
	chs(k+1,t);
}
inline void solve(){
	ans=1e9;
	memset(head,-1,sizeof(head));
	cnt=0;
	cin>>n>>p;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	chs(1,0);
	cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
