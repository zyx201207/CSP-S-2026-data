#include<bits/stdc++.h>
using namespace std;
const int lim=1e6+5; 
int t,n,m,N,vis[lim],v[lim],dis[lim];
vector<int>a[lim];
void dfs(int x){
	vis[x]=1;
	for(int y:a[x]){
		if(vis[y])continue;
		 if(v[y])dfs(y);
	}
}
int bfs(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		dis[i]=-1;
		if(v[i]){
			dis[i]=0;
			q.push(i);
		}
	}
	int ret=0;
	while(!q.empty()){
		int x=q.front();q.pop();
//		cout<<x<<","<<dis[x]<<"!";
		ret=max(ret,dis[x]);
		for(int y:a[x]){
			if(dis[y]!=-1)continue;
			dis[y]=dis[x]+1;
			q.push(y);
		}
	}
	return ret;
}
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i].clear();
	for(int i=1,l,r;i<n;i++){
		scanf("%d%d",&l,&r);
		a[l].push_back(r);
		a[r].push_back(l);
	}
	N=1<<n;int ans=1e9;
	for(int base=1;base<N;base++){
		if(__builtin_popcount(base)!=m)continue;
		for(int i=1;i<=n;i++)v[i]=0;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			if((base>>(i-1))&1)v[i]=1;
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(v[i]&&!vis[i])tot++,dfs(i);
		}
		if(tot>2)continue;
		ans=min(ans,bfs());
//		cout<<ans<<","<<base<<"!!\n";
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		work();
	}
	return 0;
}
