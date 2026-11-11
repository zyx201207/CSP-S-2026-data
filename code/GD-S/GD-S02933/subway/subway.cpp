#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define int long long
using namespace std;
struct node{
	int id,dis;
};
const int inf=LLONG_MAX;
int c,n,m,d,q,w[500005],a[500005],t[500005],dis[500005];
bool vis[500005];
vector<node> g[500005];
bool operator <(const node &a,const node &b){return b.dis<a.dis;}
//idea:hall node->make g
//and dij
//ans:dis_hall+dis_en
//zhi hui bao li mei ban fa
void dij(int s){
	priority_queue<node> q;
	fill(vis+1,vis+1+m,0);
	fill(dis+1,dis+1+n,inf);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int u=t.id;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ttt:g[u]){
			int v=ttt.id,w=ttt.dis;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]) q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	//bao li dou xie bu chu lai a
	//nooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
	//18:20 last words:i give up qwq
	//afo
	//oi:2024-2026
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int k,i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int p=1;p<=k;p++){
			for(int q=p;q<=k;q++){
				if(p==q) continue;
				g[a[p]].push_back({a[q],t[p]+t[q]});
				g[a[q]].push_back({a[p],t[p]+t[q]});
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		if(g[i].size()){
//			cout<<"u: "<<i<<" v: ";
//			for(auto t:g[i]) cout<<t.id<<' ';
//		}
//		cout<<'\n';
//	}
	for(int x,y,i=1;i<=q;i++){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
