#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
struct edge{
	int cost,v;
	bool operator <(const edge &b)const{
		return cost>b.cost;
	}
};
const int M=1e7+5;
vector<node> g[M];
int a[M];
int c,n,m,d,q;
bool ch[M];
long long dis[M];
void ku(int s){
	priority_queue<edge> q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int sum=q.top().cost;
		int v=q.top().v;
		q.pop();
		if(ch[v]){
			continue;
		}
		ch[v]=1;
		for(int i=0;i<g[v].size();i++){
			node it=g[v][i];
			int u=it.v;
			int cost=it.w;
			if(dis[u]>cost+sum){
				dis[u]=cost+sum;
				q.push({dis[u],u});
			}
		}
	}
}
void solve(){
	int s,t;
	cin>>s>>t;
	memset(dis,0x3f,sizeof(dis));
	memset(ch,0,sizeof(ch));
	ku(s);
	cout<<dis[t]+a[s]+a[t]<<endl;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		int v[cnt+5],cost[cnt+5];
		for(int j=1;j<=cnt;j++){
			cin>>v[j]>>cost[j];
			g[v[j-1]].push_back({v[j],cost[j]});
		}
	}
	while(q--){
		solve();
	}
	return 0;
}
