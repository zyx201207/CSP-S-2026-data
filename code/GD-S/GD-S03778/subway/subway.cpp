#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
using ll=long long;
const int MAXN=5e2+5,MAXD=25,MAXM=5e5+5;
struct node{
	int to;
	ll w;
	bool operator<(const node& b)const{
		return w>b.w;
	}
};
//int adj[MAXM*2+MAXD][MAXM*2+MAXN];//???????i,?????i+m?????????i+2m
namespace solve18{
	int n,m,d,q;
	ll dis[405*2+205];//1~8
vector<node>G[MAXM*2+MAXN];
void solve18(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		ll w;
		cin>>w;
		G[i].push_back({i+m,w});
		G[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			G[2*m+i].push_back({m+a,t});
			G[m+a].push_back({2*m+i,t});
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		for(int i=0;i<405*2+205;i++)
			dis[i]=LLONG_MAX;
		priority_queue<node>q;
		dis[xr]=0;
		q.push({xr,0});
		while(!q.empty()){
			node cur=q.top();
			q.pop();
			int u=cur.to;
			for(node edge:G[u]){
				int to=edge.to,w=edge.w;
				if(dis[u]+w<dis[to]){
					dis[to]=dis[u]+w;
					q.push({to,dis[to]});
				}
			}
		}
		cout<<dis[yr]<<'\n';
	}
}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int c;
	cin>>c;
	if(c<=15)
		solve18::solve18();
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
