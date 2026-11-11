#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int vis[510],lt[510],w[500010],t[510][500010];
long long ans,dis[500010];
vector<int>s1[510],s2[500010];
vector<pair<long long,int>>e[510];
void bfs(int x,int y){
	memset(lt,0,sizeof lt);
	memset(vis,0,sizeof vis);
	memset(dis,127,sizeof dis);
	priority_queue<pair<long long,int>>q;
	for(auto v:s2[x]){
		q.push({t[v][x],v});
		dis[v]=t[v][x];
	}
	for(auto v:s2[y]){
		lt[v]=1;
	}
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(vis[u.second]){
			continue;
		}
		vis[u.second]=1;
		//if(lt[u.second]){
		//	continue;
		//}
		for(auto i:e[u.second]){
			if(dis[u.second]+i.first<dis[i.second]){
				dis[i.second]=dis[u.second]+i.first;
				q.push({dis[i.second],i.second});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			s1[i].push_back(x);
			s2[x].push_back(i);
			t[i][x]=y;
			if(s2[x].size()>1){
				for(auto v:s2[x]){
					if(i!=v){
						e[i].push_back({t[i][x]+t[v][x],v});
						e[v].push_back({t[i][x]+t[v][x],i});
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		ans=LONG_LONG_MAX;
		bfs(x,y);
		for(int i=1;i<=500;++i){
			if(dis[i]+t[i][y]<ans && lt[i]==1){
				ans=dis[i]+t[i][y];
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
