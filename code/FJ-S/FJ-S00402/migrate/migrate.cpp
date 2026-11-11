#include<bits/stdc++.h>
#define int long long
#define MAX_N 2000010
#define inf LLONG_MAX
using namespace std;
int c,t,ans = 0;
int n,d;
int x[MAX_N];
vector<int> edge[MAX_N];
struct Node {
	int ind,dis;
	const bool operator>(const Node x) const {
		return dis > x.dis;
	}
};
int vis[MAX_N],dist[MAX_N],cnt[MAX_N];
priority_queue<Node,vector<Node>,greater<Node>> que;
void dij(int s) {
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++) {
		dist[i] = inf;
		if(i == s) dist[i] = 0;
	}
	while(!que.empty()) que.pop();
	que.push({s,0});
	while(!que.empty()) {
		int ind = que.top().ind;
		que.pop();
		if(vis[ind] == true) continue;
//		cout<<"---------------------------test"<<ind<<endl;
//		for(int i = 1;i<=n;i++) {
//			cout<<dist[i]<<" ";
//		}
//		cout<<endl;
		vis[ind] = true;
		for(auto v:edge[ind]) {
			if(dist[ind] + 1 < dist[v]) {
				cnt[v] = 1;
				dist[v] = dist[ind] + 1;
				que.push({v,dist[v]});
			}else if(dist[ind] + 1 == dist[v]){
				cnt[v]++;
			}
		}
//		for(int i = 1;i<=n;i++) {
//			cout<<dist[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int i = s+1;i<=n;i++) {
		if(cnt[i] == 2) ans++;
	}
	return ;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		ans = 0;
		for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<n;i++) edge[i].push_back(i+1);
		int l = 1;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			while(l<i-1 && x[i] - x[l] > d) {
				l++;
			}
			for(int j = l;j<i-1;j++) {
				edge[j].push_back(i);
			}
		}
		for(int i = 1;i<=n;i++) {
			dij(i);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
