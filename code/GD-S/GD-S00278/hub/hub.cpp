#include <bits/stdc++.h>
using namespace std;
vector<long long> vec[105];
long long n,k,ans=0x3f3f3f3f3f3f3f3f;
bool b[105],vis[105];
void mark(long long u){
	vis[u]=1;
	for(long long v:vec[u]){
		if(b[v]==1&&vis[v]==0)mark(v);
	}
}
bool check(){
	long long cnt=0;
	memset(vis,0,sizeof vis);
	for(long long i=1;i<=n;i++){
		if(b[i]==1&&vis[i]==0){
			mark(i);
			cnt++;
		}
	}
	return cnt<=2;
}
long long dis[105];
long long bfs(long long s){
	dis[s]=0;
	queue<long long> q;
	q.push(s);
	while(!q.empty()){
		long long u=q.front();
		q.pop();
		if(b[u]==1)return dis[u];
		for(long long v:vec[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=min(dis[v],dis[u]+1);
				q.push(v);
			}
		}
	}
	return 0x3f3f3f3f3f3f3f3f;
}
long long calc(){
	long long ret=0;
	for(long long i=1;i<=n;i++){
		memset(dis,0x3f,sizeof dis);
		ret=max(ret,bfs(i));
	}
	return ret;
}
void debug(){
	for(int i=1;i<=n;i++){
		if(b[i])cout<<i<<" ";
	}
	cout<<endl;
}
void dfs(long long i,long long cnt){
	if(i==n+1){
		if(check()&&cnt==k){
			ans=min(ans,calc());
			//debug();
		}
		return;
	}
	b[i]=0;
	dfs(i+1,cnt);
	if(cnt<k){
		b[i]=1;
		dfs(i+1,cnt+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		ans=0x3f3f3f3f3f3f3f3f;
		cin>>n>>k;
		for(long long i=1;i<=n;i++){
			vec[i].clear();
		}
		for(long long i=1;i<n;i++){
			long long u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
}
