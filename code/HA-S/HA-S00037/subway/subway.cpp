#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define pll pair<int,int>
const int N=5e5+5,M=5e2+5;
int sz,n,m,d,T;
vector<pll>edge[M];//every line's subway station
int c[N];// every line's size of subway station
vector<pll>zhan[N];// every subway station's line
int shang[N];
ll dis[N];
bool vis[N];
vector<pll>ask[N];
ll res[N];
struct node{
	ll val,x,zt;
};
priority_queue<node>q;
bool operator<(node x,node y){
	return x.val>y.val;
}
void init(){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=INF;
	while(!q.empty())q.pop();
}
void dij(int s){
	init();
	q.push({0,s,0});
	dis[s]=0;
	while(!q.empty()){
		int val=q.top().val,x=q.top().x,now=q.top().zt;q.pop();
//		cout<<x<<" "<<now<<endl;
		
		if(vis[x])continue;
		vis[x]=1;
		for(pll pp:zhan[x]){
			int zt=pp.first,wei=pp.second;
			for(pll p:edge[zt]){
				int v=p.first,w=p.second;
				if(v==x)continue;
				if(zt==now&&!vis[v]&&dis[v]>val+w){
					dis[v]=val+w;
					q.push({dis[v],v,zt});
				}
				if(zt!=now&&!vis[v]&&dis[v]>val+w+edge[zt][wei-1].second){
					dis[v]=dis[x]+w+edge[zt][wei-1].second;
					q.push({dis[v],v,zt});
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>sz>>m>>n>>d>>T;
	for(int i=1;i<=n;i++)cin>>shang[i];
	for(int i=1;i<=m;i++){
		cin>>c[i];
		for(int j=1;j<=c[i];j++){
			int x,w;cin>>x>>w;
			edge[i].push_back({x,w});
			zhan[x].push_back({i,j});
		}
	}
	for(int i=1;i<=T;i++){
		int x,y;cin>>x>>y;
		ask[x].push_back({y,i});
	}
	for(int i=1;i<=n;i++){
		if(ask[i].empty())continue;
		dij(i);
		for(pll p:ask[i])
			res[p.second]=dis[p.first]+shang[i]+shang[p.first];
	}
	for(int i=1;i<=T;i++)cout<<res[i]<<endl;
//	cout<<clock();
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

