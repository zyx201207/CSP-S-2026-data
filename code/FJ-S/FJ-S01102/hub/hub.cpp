#include <bits/stdc++.h>
using namespace std;
vector<int> g[15];
int n,k,f[15],dis[15];
void bfs1(int s){
	queue<int> q;
	q.push(s);
	dis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if((!f[v])||dis[v]) continue;
			q.push(v);
			dis[v]=1;
		}
	}
}
int bfs2(int s){
	for(int i=1;i<=n;i++) dis[i]=100;
	int ans=100;
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dis[v]<dis[u]+1) continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]) ans=min(ans,dis[i]);
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _c,_,ans=100;
	cin>>_c>>_;
	while(_--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=100;
		for(int bt=0;bt<(1<<n);bt++){
			int tot=0;
			for(int i=0;i<n;i++){
				int b=((bt>>i)&1);
				f[i+1]=b;
				tot+=b;
				dis[i+1]=0;
			}
			if(tot!=k) continue;
			tot=0;
			memset(dis,0,sizeof(dis));
			for(int i=1;i<=n;i++){
				if((!dis[i])&&f[i]){
					bfs1(i);
					tot++;
//					cout<<bt<<","<<i<<"\n";
				}
			}
			if(tot>2) continue;
			int t=0;
			for(int i=1;i<=n;i++){
				int p=bfs2(i);
				t=max(t,p);
			}
//			cout<<"**"<<bt<<","<<t<<"   "<<tot<<"\n";
			ans=min(ans,t);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
