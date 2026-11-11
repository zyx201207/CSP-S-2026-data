#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long 
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int a[N];
int w[N];
int k[N];
int ans;
struct node{
	int a,t;
}b[550][N];
struct edge{
	int id,v;
};
vector<edge>g[550];
int d[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void dij(int s,int t){
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j].a>>b[i][j].t;
		}
		for(int j=2;j<=k[i];j++){
			g[b[i][j-1].a].push_back({i,b[i][j-1].a});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dij(x,y);
	}
	return 0;
}
