#include<bits/stdc++.h>
using namespace std;
int t,n,k,vis[1000005],dist[1000005],ans;
vector<int>g[1000005],use;
unordered_map<int,bool>mp;
queue<int>q;
void dfs(int u){
	vis[u]=1;
	for(int v:g[u])if(!vis[v]&&mp.count(v))dfs(v);
}
void bfs(int s){
	q.push(s);
	dist[s]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:g[u])
			if(dist[u]+1<dist[v]){
				dist[v]=dist[u]+1;
				q.push(v);
			}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		if(k==n-1){
			cout<<"1\n";
			continue;
		}
		for(int s=(1<<k)-1;s<(1<<n);s++){
			int cnt=0;
			vector<int>a;
			mp.clear();
			for(int i=0;i<n;i++)
				if((s>>i)&1){
					cnt++;
					a.push_back(i+1);
					mp[i+1]=1;
				}
			if(cnt!=k)continue;
			cnt=0;
			memset(vis,0,sizeof vis);
			for(int u:a){
				if(!vis[u]){
					dfs(u);
					cnt++;
				}
				if(cnt>2)break;
			}
			if(cnt>2)continue;
			int sum=0;
			memset(dist,0x3f,sizeof dist);
			for(int u:a)bfs(u);
			for(int i=1;i<=n;i++)sum=max(sum,dist[i]);
			ans=min(ans,sum);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
