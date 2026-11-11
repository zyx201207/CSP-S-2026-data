//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef long long ll;
constexpr const int N=2e6,inf=0x3f3f3f3f;
int n;
vector<int>g[N+1];
void Dijkstra(int s,ll &ans){
	static int dis[N+1],cnt[N+1];
	static bool vis[N+1];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	fill(dis+1,dis+n+1,inf);
	fill(vis+1,vis+n+1,0);
	dis[s]=0;
	cnt[s]=1;
	q.push({dis[s],s});
	while(q.size()){
		auto [value,x]=q.top();
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=true;
		for(int v:g[x]){
			if(dis[x]+1<dis[v]){
				dis[v]=dis[x]+1;
				cnt[v]=cnt[x];
				q.push({dis[v],v});
			}else if(dis[x]+1==dis[v]){
				cnt[v]+=cnt[x];
			}
		}
	}
	for(int i=s+1;i<=n;i++){
		if(cnt[i]==2){
			ans++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int cid,T;
	cin>>cid>>T;
	while(T--){
		static ll d,x[N+1];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].resize(0);
		}
		for(int i=1;i<=n;i++){
			int l=lower_bound(x+1,x+n+1,x[i]-d)-x;
			int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			for(int j=l;j<=r;j++){
				g[i].push_back(j);
			}
		}
		ll ans=0;
		for(int u=1;u<=n;u++){
			Dijkstra(u,ans);
		}
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

2
*/
/*
//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;
typedef long long ll;
constexpr const int N=2e6,inf=0x3f3f3f3f;
int n,depth[N+1],father[N+1],cntd[N+1];
set<int>g[N+1],rg[N+1];
vector<tuple<int,int,int>> check(int x){
	vector<tuple<int,int,int>>ans;
	for(int u:g[x]){
		for(int v:g[x]){
			if(u>=v){
				continue;
			}
			for(int a:g[u]){
				for(int b:g[v]){
					if(a!=b){
						continue;
					}
					if(g[x].count(a)){
						continue;
					}
					bool flag=true;
					for(int r:g[x]){
						if(r!=u&&r!=v&&g[r].count(a)){
							flag=false;
							break;
						}
					}
					if(flag){
						ans.push_back({u,v,a});
					}
				}
			}
		}
	}
	return ans;
}
int dfs(int x,int u,int v,int root){
	cerr<<"dfs("<<x<<","<<u<<","<<v<<","<<root<<")\n";
	if(x!=root&&rg[x].size()!=1){
		return 0;
	}
	if(check(x).size()){
		return 1;
	}
	int ans=1;
	for(int y:g[x]){
		if(depth[y]!=depth[x]){
			ans+=dfs(y,u,v,root);
		}
	}
	return ans;
}
ll calc(int x,int u,int v,int y){
	cerr<<"calc("<<x<<","<<u<<","<<v<<","<<y<<")\n";
	int up=1;
	while(true){
		x=father[x];
		if(!x||g[x].count(u)||g[x].count(v)||g[x].size()>1){
			break;
		}
		up++;
	}
	int down=dfs(y,u,v,y);
	cerr<<"return "<<up<<"*"<<down<<'\n';
	return 1ll*up*down;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int cid,T;
	cin>>cid>>T;
	while(T--){
		static ll d,x[N+1];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
			rg[i].clear();
			depth[i]=0;
			cntd[i]=0;
		}
		for(int i=1;i<=n;i++){
			int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			cerr<<i<<" -> "<<"["<<i+1<<","<<r<<"]\n";
			for(int j=i+1;j<=r;j++){
				g[i].insert(j);
				if(!depth[j]){
					rg[j].insert(i);
					depth[j]=depth[i]+1;
					father[j]=i;
					cntd[i]++;
				}
			}
		}
		ll ans=0;
		for(int x=1;x<=n;x++){
			auto pl=check(x);
			cerr<<"pl["<<x<<"]=";
			for(auto [u,v,y]:pl){
				cerr<<"("<<x<<' '<<u<<' '<<v<<' '<<y<<")\n";
			}
			cerr<<'\n';
			for(auto [u,v,y]:pl){
				ll pl=calc(x,u,v,y);
				ans+=pl;
			}
		}
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);
	return 0;
}
0 1
5 2
1 2 3 4 5

2
*/
