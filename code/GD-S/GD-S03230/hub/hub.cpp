#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>g[4005];
int dis[4005];
void solve1(){
	for(int i=1;i<=4000;i++)
		g[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	//cout<<"Yes";
	int ans=1e9;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			queue<int>q;
			q.push(i);
			q.push(j);
			memset(dis,0x3f,sizeof dis);
			dis[i]=dis[j]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:g[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push(v); 
					}
				}
			} 
			int cnt=0;
			for(int i=1;i<=n;i++){
				cnt=max(cnt,dis[i]);
			}
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==7||c==11||c==12)
			solve1();
	}
} 


