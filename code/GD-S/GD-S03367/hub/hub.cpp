#include<iostream>
using namespace std;
int c,t,n,k,u,v,ans;
int e[2000003],to[2000003],h[1000003],dis[1003][1003],cnt;
bool vis[1000003];
void dfs(const int&rt,const int&id,const int&f){
	for(int i=h[id];i;i=to[i]){
		if(e[i]==f)continue;
		dis[rt][e[i]]=dis[rt][id]+1;
		dfs(rt,e[i],id);
	}
}
int f[666];
int findf(int x){
	if(f[x]==x)return x;
	return f[x]=findf(f[x]);
}
void dfs0(const int&id,const int&x){
	if(x==k||id-1-x==n-k){
		if(x<k){
			for(int i=id;i<=n;i++)vis[i]=true;
		}else for(int i=id;i<=n;i++)vis[i]=false;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int j=h[i];j;j=to[j]){
					if(vis[e[j]])f[findf(e[j])]=findf(i);
				}
			}
		}
		{
			int x=0,y=0;
			for(int j=1;j<=n;j++){
				if(vis[j]){
					if(!x)x=findf(j);
					else if(findf(j)!=x){
						if(!y)y=findf(j);
						else if(findf(j)!=y)return;
					}
				}
			}
		}
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			int tt=n;
			for(int j=1;j<=n;j++){
				if(!vis[j])continue;
				tt=min(tt,dis[i][j]);
			}
			tmp=max(tt,tmp);
		}
		ans=min(tmp,ans);
		return;
	}
	vis[id]=false;
	dfs0(id+1,x);
	vis[id]=true;
	dfs0(id+1,x+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[++cnt]=u;to[cnt]=h[v];
			h[v]=cnt;
			e[++cnt]=v;to[cnt]=h[u];
			h[u]=cnt;
		}
		for(int i=1;i<=n;i++)dfs(i,i,0);
		ans=n;
		dfs0(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
