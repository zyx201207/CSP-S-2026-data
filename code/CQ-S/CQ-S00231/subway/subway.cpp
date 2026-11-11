#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
struct node{
	int to;
	long long w;
};
vector<node> g[N];
long long dis[505][505],tim[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tim[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a;
			long long t;
			cin>>a>>t;
			g[a].push_back({i,t});
		} 
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) if(i!=j) dis[i][j]=1e17;
	for(int i=1;i<=m;i++){
		for(auto u:g[i]){
			for(auto v:g[i]){
				if(u.to!=v.to){
					dis[u.to][v.to]=min(dis[u.to][v.to],u.w+v.w);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=2e18;
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(ans,tim[x]+tim[y]+dis[u.to][v.to]+u.w+v.w);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

