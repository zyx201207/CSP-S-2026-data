#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int c,n,m,d,q;
int w[N];
int dis[N];
struct node{
	int v,val;
};
vector<node>e[N];
unordered_map<int,unordered_map<int,int>>t;
bool vis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>qp;
inline void dj(int s){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s]=w[s];
	qp.push({w[s],s});
	while(!qp.empty()){
		int u=qp.top().second;
		qp.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:e[u]){
			int v=it.v,val=it.val;
			if(dis[v]>dis[u]+val){
				dis[v]=dis[u]+val;
				qp.push({dis[v],v});
			}
		}
	}
}
//set<int>s[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
//			s[i].insert(a);
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		dj(l);
		cout<<dis[r]+w[r]<<'\n';
	}
	return 0;
}