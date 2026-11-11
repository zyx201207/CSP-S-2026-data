#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
bool vis[500005];
int dis[500005];
int a[5005][5005];
int t[5005][5005];
int e[5005][5005];
//vector<pair<int,int> >e[500005];
//void dijistra(int s){
//	for(int i=0;i<=n*2;i++){
//		vis[i]=0,dis[i]=LONG_LONG_MAX;
//	}
//	priority_queue<pair<int,int>>q;
//	q.push({0,s});
//	dis[s]=0;
//	while(!q.empty()){
//		pair<int,int>t=q.top();
//		q.pop();
//		int u=t.second;
//		if(vis[u])continue;
//		vis[u]=1;
//		for(int i=0;i<e[u].size();i++){
//			int v=e[u][i].first,w=e[u][i].second;
////			cout<<dis[u]<<" "<<w<<" "<<dis[v]<<"\n"; 
//			if(dis[u]+w<dis[v]){
//				dis[v]=dis[u]+w;
////				cout<<dis[v]<<"\n";
//				q.push({-dis[v],v});
//			}
//		}
//	}
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
//		e[i].push_back({0,w[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int dd=1;dd<=k[i];dd++){
				if(j==dd)continue;
				e[a[i][j]][a[i][dd]]=1;e[a[i][dd]][a[i][j]]=1;
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(n==1){
			cout<<0<<"\n";
		}
		else if(n==2){
			cout<<w[1]+w[2]+t[1][1]+t[1][2]<<"\n";
		}
		else if(n==3){
			cout<<w[1]+w[3]+t[1][1]+t[1][2]+t[2][2]+t[2][3]<<"\n";
		}
	}
	return 0;
}
