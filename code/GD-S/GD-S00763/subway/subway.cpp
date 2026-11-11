#include<bits/stdc++.h>
#define ll long long
#define N 10010
using namespace std;
int c,n,m,d,q;
ll w[N],a[N][N],t[N][N],ans=1e9,dis[N];//t[i][j]表示在j号线中从编号为i的地铁站站台走到这个地铁站站厅的用时 
vector<int> g[N];//i号线经过的站点存入g[i]
vector<int> T[N];//经过编号为i的地铁站的线路存入T[i]
struct node{
	int u;
	ll dis;
	bool operator<(const node& other)const{
		return dis>other.dis;
	}
};
vector<node> mp[N];//缩点后的图 
bool vis[N];
int DJ(int s,int t){
	for(int i=1;i<=n;i++) dis[i]=1e9;
	for(int i=1;i<=n;i++) vis[i]=0;
	priority_queue<node> q;
	dis[s]=0;
	q.push({s,0});
	while(q.size()){
		node to=q.top();
		q.pop();
		if(vis[to.u]) continue;
		vis[to.u]=1;
		for(auto v:mp[to.u]){
			if(dis[v.u]>=dis[to.u]+v.dis){
				dis[v.u]=dis[to.u]+v.dis;
				q.push({v.u,dis[v.u]});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,x;//编号为x的地铁站
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>t[x][i];
			g[i].push_back(x);
			T[x].push_back(i); 
		} 
	}
	for(int i=1;i<=n;i++){//对n条地铁线路进行缩点,先看它们之间的连线,i也是线路 
		for(int v:g[i]){//v是地铁站 
			for(int v1:T[v]){//v1是线路 
				if(v1==i) continue;
				int tmp=t[v][v1]+t[v][i];
				mp[i].push_back({v1,tmp});
				mp[v1].push_back({i,tmp});
			}
		}
	}
	while(q--){
		int ans=0,s,t;
		cin>>s>>t;
		ans=DJ(s,t)+w[s]+w[t];
		cout<<ans<<endl;
	}
	return 0;
}
