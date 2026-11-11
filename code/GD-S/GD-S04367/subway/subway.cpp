#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using ll=long long;
using namespace std;
//solve1
//see every sub , every station ,every mix(sub,sta) as a dian
const int N=5e5+10;
const int ALL=N+1010;
ll w[N];
ll dis[ALL];
bool vis[ALL];
int womeiyouyong, n, m, d, q;
int tot=0;
struct EDGE{
	int v;
	ll quan;
};
vector<EDGE> mp[ALL];
void dijkstral(const int &u,const int &v){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[u]=0;
	for(int tm=1;tm<=tot;tm++){
		int id;
		ll minn=INF;
		for(int i=1;i<=tot;i++){
			if(minn>dis[i]&&vis[i]==0){
				id=i;
				minn=dis[i];
			}
		}
		vis[id]=1;
		for(auto e:mp[id]){
			int to=e.v;
			ll quan=e.quan;
			if(vis[to]==0&&dis[to]>dis[id]+quan){
				dis[to]=dis[id]+quan;
			}
		}
	}
	cout<<dis[v]+((long long)(w[u]))+((long long)(w[v]))<<'\n';
}
void solve1(){
	while(q--){
		int u,v;
		cin>>u>>v;
		dijkstral(u,v); 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0); 
	cin>>womeiyouyong>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
	cin>>w[i];}
	tot=m;
	for(int i=1;i<=n;i++){
		++tot;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to;ll quan;
			cin>>to>>quan;
			mp[tot].push_back({to,quan});
			mp[to].push_back({tot,quan});
		}
	}
	solve1(); 
	return 0;
}
