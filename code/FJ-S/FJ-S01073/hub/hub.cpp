#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans=999999999;
vector<int> G[1000006];
int a[1000006];
bool vis[1000006],in[1000006];
void dfs1(int deep,int last){
	if(deep>k){
		queue<int> q;
		int cnt=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=k;i++){
			if(vis[a[i]]) continue;
			q.push(a[i]);
			cnt++;
			if(cnt>2) return ;
			while(q.size()){
				int u=q.front();
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				for(int i=0;i<G[u].size();i++)
					if(!vis[G[u][i]] && in[G[u][i]]) q.push(G[u][i]);
			}
		}
		queue<pair<int,int> > q1;
		int res=0;
		for(int i=1;i<=n;i++) if(vis[i]) {q1.push({0,i});vis[i]=0;}
		while(q1.size()){
			int x=q1.front().first,u=q1.front().second;
			q1.pop();
			if(vis[u]) continue;
			vis[u]=1;
			res=max(x,res);
			for(int i=0;i<G[u].size();i++)
				if(!vis[G[u][i]])
					q1.push({x+1,G[u][i]});
		}
//		for(int i=1;i<=k;i++) cout<<a[i]<<" ";cout<<"\n"<<res<<"\n";
		ans=min(ans,res);
		return ;
	}
	for(int i=last+1;i<=n;i++){
		a[deep]=i;
		in[i]=1;
		dfs1(deep+1,i);
		in[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=999999999;
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int u,v,i=1;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1,0);
		cout<<ans<<"\n";
	}
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/