#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500010];//a[]地口时间 
vector<pair<int,int>> g[1010];
//bool vis[]
//void dij(int b,int e){
//	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//	pq.push({g[b].second,b});
//	
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int sh;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			if(j!=1){
				g[u].push_back({sh,0});
				g[sh].push_back({u,0});
			}
			sh=u;
			g[u+500].push_back({u,w});
			g[u].push_back({u+500,w});
		}
	}
	for(int i=1;i<=q;i++){
		int b,e;
		cin>>b>>e;
//		dij(b,e);
		cout<<a[b]+a[e]<<endl;
	}
	return 0;
} 
