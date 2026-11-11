#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,ans,dis[1000010];
bool vis[1000010];
vector<int>a[1000010];
void djs(){
	priority_queue<pair<int,int>>p;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) if(vis[i]) dis[i]=0,p.push({0,i});
	while(!p.empty()){
		int u=p.top().second;
		p.pop();
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				p.push({-dis[v],v});
			}
		}
	}
	return;
}
void dfs(int x,int y,int z){
	if(x>n){
		if(y!=k) return;
		djs();
		int sum=0;
		for(int i=1;i<=n;i++) sum=max(sum,dis[i]);
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,y,z);
	if(y<k){
		if(z==0){
			vis[x]=1;
			dfs(x+1,y+1,1);
			vis[x]=0;
		}
		else{
			bool flag=0;
			for(int i=0;i<a[x].size();i++){
				if(vis[a[x][i]]) flag=1;
				if(flag) break;
			}
			if(flag){
				vis[x]=1;
				dfs(x+1,y+1,z);
				vis[x]=0;
			}
			else if(z==1){
				vis[x]=1;
				dfs(x+1,y+1,2);
				vis[x]=0;
			}
		}
	}
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++) a[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
