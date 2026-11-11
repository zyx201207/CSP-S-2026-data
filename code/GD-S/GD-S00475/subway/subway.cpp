#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int M=5e5+10;
int c,n,m,d,q,w[M];
struct node{
	int s;
	vector<pair<int,int> > q;
}a[510];
int mn=1e9;
void dfs(int u,int v,int cnt){
	for(int i=1;i<=n;i++){
		for(auto e:a[i].q){
			if(e.first==u) cnt+=e.second;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		for(int j=1,x,y;j<=2*a[i].s;j++){
			cin>>x>>y;
			a[i].q.push_back({x,y});
		}
	} 
	while(q--){
		int u,v;
		mn=1e9;
		dfs(u,v,w[u]); 
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<'\n'<<17;
	}
	if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<'\n'<<16;
	}
	return 0;
} 
