#include<bits/stdc++.h>
using namespace std;
int n,k,u[25],v[25];
int head[1000005],nxt[2000005],to[2000005],cnt;
void add(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
int vis[25];
int fa[25];
int dis[25];
void init(int n){
	for(int i=1;i<=n;i++)	fa[i]=i;
}
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}
void dfs(int u,int fa,int idis){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa)	continue;
		if(!vis[v]){
			dis[v]=min(dis[v],idis+1);
		}
		dfs(v,u,idis+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==1){
		int lst=0;
		while(t--){
			for(int i=1;i<=lst;i++)	head[i]=0;
			cnt=0;
			cin>>n>>k;
			lst=n;
			for(int i=1;i<n;i++){
				cin>>u[i]>>v[i];
				add(u[i],v[i]),add(v[i],u[i]);
			}
			int ans=1e9;
			for(int mask=0;mask<(1<<n);mask++){
				int sum=0;
				for(int i=0;i<n;i++){
					if((mask>>i)&1)	sum++;
				}
				if(sum!=k)	continue;
				for(int i=0;i<n;i++){
					if((mask>>i)&1)	vis[i+1]=1;
				}
				init(n);
				for(int i=1;i<n;i++){
					if(vis[u[i]]==vis[v[i]]&&vis[u[i]]==1)	merge(u[i],v[i]);
				}
				int kuai=0;
				for(int i=1;i<=n;i++){
					if(vis[i]&&fa[i]==i)	kuai++;
				}
				if(kuai>2){
					for(int i=0;i<n;i++){
						if(vis[i])	vis[i]=0;
					}						
					continue;
				}
				memset(dis,0x3f,sizeof dis);
				for(int i=1;i<=n;i++){
					if(vis[i]){
						dis[i]=0;
						dfs(i,0,0);
					}
				}
				int res=-1e9;
				for(int i=1;i<=n;i++)	res=max(res,dis[i]);
				ans=min(ans,res);
				for(int i=0;i<n;i++){
					if(vis[i])	vis[i]=0;
				}		
			}
			cout<<ans<<"\n";
		}		
	}else if(c==13||c==14){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1,u,v;i<n;i++)	cin>>u>>v;
			if(n==k){
				cout<<0<<"\n";
				continue;
			}
			if((n+1)/2<=k){
				cout<<1<<"\n";
				continue;
			}
			int l=2,r=n,ans;
			while(l<=r){
				int mid=l+r>>1;
				int pos=3*(mid-1)+k;
				if((n+1)/2-pos<=mid)	ans=mid,r=mid-1;
				else	l=mid+1;
			} 
			cout<<ans<<"\n";
		}
	} 
	return 0;
}
