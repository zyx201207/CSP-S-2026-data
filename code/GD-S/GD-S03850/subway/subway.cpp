#include<iostream>
#include<cstring>
#include<vector> 
#define int long long 
using namespace std;
int n,a[500005],ccid,ans,m,d,q;
struct node{
	int v,w;
};
vector<node>st[500005];
int dis[505][505],len,lve[500005];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>ccid>>n>>m>>d>>q;
	memset(dis,63,sizeof(dis));
	for(int i =1;i<=m;i++){
		cin>>a[i];
	}
	for(int i =1;i<=n;i++){
		cin>>len;
		for(int j =1;j<=len;j++){
			int v,w;cin>>v>>w;
			st[v].push_back({i,w});
		}
	} 
	for(int i =1;i<=m;i++){
		for(int j =0;j<st[i].size();j++){
			for(int k =0;k<st[i].size();k++){
				if(j==k)continue;
				int u = st[i][j].v,v = st[i][k].v;
				dis[u][v] = min(dis[u][v],st[i][j].w+st[i][k].w);
				dis[v][u] = min(dis[v][u],st[i][j].w+st[i][k].w);
			}
		}
	}
	for(int i =1;i<=n;i++)dis[i][i] = 0;
	for(int k =1;k<=n;k++){
		for(int i =1;i<=n;i++){
			for(int j =1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			} 
		}
	}
	while(q--){
		ans = 1e18;
		int x,y;cin>>x>>y;
		for(auto i:st[x]){
			for(auto j:st[y]){
				int u = i.v,v = j.v;
//				cout<<u<<" "<<v<<" "<<dis[u][v]<<" "<<a[x]+a[y]+i.w<<"\n";
				ans = min(ans,dis[u][v]+a[x]+a[y]+i.w+j.w);
			}
		} 
		cout<<ans<<"\n";
	}
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/ 
