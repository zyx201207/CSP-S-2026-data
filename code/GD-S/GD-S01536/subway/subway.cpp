#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int None=5e2+5,Ntwo=5e5+5;
int c,n,m,d,p;
int k[None],a[None][Ntwo];
vector<int> T[None];
map<string,vector<pair<string,ll>>> g;
string bd(string s,int x){
	return s+to_string(x);
}
struct Node{
	ll di;
	string id;
	bool operator>(const Node& _n) const {return di>_n.di; }
};
priority_queue<Node,vector<Node>,greater<Node>> q;
map<string,bool> vis;
map<string,ll> dis;
ll djikstra(string sta,string en){
	for(int i=1;i<=m;i++){
		vis[bd("E",i)]=0,dis[bd("E",i)]=1e17;
		vis[bd("H",i)]=0,dis[bd("H",i)]=1e17;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			vis[bd("P",a[i][j])+to_string(i)]=0,dis[bd("P",a[i][j])+to_string(i)]=1e17;
		}
	}
	q.push({0,sta});
	dis[sta]=0;
	while(!q.empty()){
		string u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u]){
			string v=e.first;
			ll w=e.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1,w;i<=m;i++){
		cin>>w;
		g[bd("H",i)].push_back({bd("E",i),w});
		g[bd("E",i)].push_back({bd("H",i),w});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		T[i].push_back(-1);
		for(int j=1,TMP;j<=k[i];j++){
			cin>>a[i][j]>>TMP;
			T[i].push_back(TMP);
			g[bd("P",a[i][j])+to_string(i)].push_back({bd("H",a[i][j]),T[i][j]});
			g[bd("H",a[i][j])].push_back({bd("P",a[i][j])+to_string(i),T[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			g[bd("P",a[i][j])+to_string(i)].push_back({bd("P",a[i][j-1])+to_string(i),0});
			g[bd("P",a[i][j-1])+to_string(i)].push_back({bd("P",a[i][j])+to_string(i),0});
		}
	}
	while(p--){
		int xr,yr;
		cin>>xr>>yr;
		cout<<djikstra(bd("E",xr),bd("E",yr))<<'\n';
	}
	return 0;
} 
