#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,n,k,res,ans;
int dis[N];
vector<int>ve[N];
map<int,bool>vis;
void bfs(int s1,int s2){
	queue<int>q;
	vis.clear();
	q.push(s1);
	q.push(s2);
	dis[s1]=0,vis[s1]=1;
	dis[s2]=0,vis[s2]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:ve[u]){
			if(vis[v]==0){
				vis[v]=1;
				dis[v]=dis[u]+1;
				res=max(res,dis[v]);
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=N;
		for(int i=1;i<=n;i++) ve[i].clear();
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		if(k==n) ans=0;
		else if(k>=n-4) ans=1;
		else if(k==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					res=0;
					bfs(i,j);
					ans=min(ans,res);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
