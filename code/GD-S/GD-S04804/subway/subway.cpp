#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 5e5+5;
const int inf = 2e9+5;
int c,n,m,d,q;
int w[maxn];
struct station{
	int id;//哪一条线路；
	int hal,whal;//该站台对应的地铁站的编号，到站厅的代价 
	int nxt;//下一站台的编号
}sta[maxn];
vector<int>g[maxn];
vector<pii>e[maxn];
void init();
void init1(){
	for(int u = 1,now,v,w;u<=m;u++){
//		cout<<u<<'\n';
		for(int x : g[u]){
			now = x;
			while(sta[now].nxt!=0){//如果下一个站台非空 
				now = sta[now].nxt;//前往下一个站台 
				v = sta[now].hal;//获取地铁站编号 
				w = sta[now].whal+sta[x].whal;
//				cout<<now<<" "<<sta[now].nxt<<" ";
//				cout<<u<<" "<<v<<" "<<w<<"\n";
				e[u].push_back({v,w});
				e[v].push_back({u,w});
			}
		}
	}
//	for(int i = 1;i<=m;i++){
//		cout<<i<<"\n";
//		for(auto x : e[i]){
//			cout<<x.first<<" "<<x.second<<'\n';
//		}
//	} 
}
int dis[maxn];
int inq[maxn];
long long solve1(int begin,int end){
	for(int i = 1;i<=m;i++)dis[i] = inf,inq[i] = 0;
	dis[begin] = 0,inq[begin] = 1;
	priority_queue<int,vector<int>,greater<int>>que;
	que.push(begin);
	int u,v,w;
	while(!que.empty()){
		u = que.top();
		que.pop();
		for(auto x : e[u]){
			v = x.first,w = x.second;
			if(dis[v]>dis[u]+w){
				dis[v] = dis[u]+w;
				if(!inq[v])que.push(v);
			}
		}
	}
	return dis[end]*1ll;
}
int main(){
//	freopen("subway1.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)cin>>w[i];
	for(int i = 1,id = 0,k;i<=n;i++){
		cin>>k;
		if(k==1)continue;
		if(c>=9&&c<=11){
			int a1,t1,a2,t2;
			cin>>a1>>t1>>a2>>t2;
			e[a1].push_back({a2,t1+t2});
			e[a2].push_back({a1,t1+t2});
		}else{
			for(int j = 1,a,t;j<=k;j++){
				cin>>a>>t;
				if(j>1)sta[id].nxt = id+1;
				sta[++id] = {i,a,t,0};
				g[a].push_back(id);
			}
		}
	}
//	for(int i = 1;i<=m;i++){
//		cout<<i<<"\n";
//		for(int x : g[i]){
//			cout<<x<<" "<<sta[x].id<<" "<<sta[x].hal<<" "<<sta[x].whal<<" "<<sta[x].nxt<<"\n";
//		}
//	}
	if(c<=8)init1();//暴力建立新边 
	for(int i = 1,b,e;i<=q;i++){
		cin>>b>>e;
		if(c<=11)cout<<solve1(b,e)+w[b]*1ll+w[e]*1ll<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
