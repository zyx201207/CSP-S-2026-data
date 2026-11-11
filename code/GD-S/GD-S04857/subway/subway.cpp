#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using ll=long long;
int w[N];
vector<pair<int,int>> g[N];
bool find(int n,vector<pair<int,int>> p){
	for(int i=0;i<p.size();i++){
		if(n==p[i].first) return true;
	}
	return false;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		ll minn=1e18;
		bool f=false;
		for(int i=1;i<=n;i++){
			if(find(x,g[i])){//第i条线上有x站 
				if(find(y,g[i])){//起点和终点在同一条线上 
					f=true;
					cout<<ans<<'\n';
					break;
				}
			}
		}
		if(f) continue;
	}
	return 0;
} 
