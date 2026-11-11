#include<bits/stdc++.h>
using namespace std;
const int N=4e3+10; 
int c,n,m,d,q,w[N],a[N][N],t[N][N];
//bool vis[N];
//void bfs(int s,int e){
//	int ans=w[s]+w[e];
//	queue<int>q;
//	q.push(s);
//	while(q.size()){
//		int x=q.front();
//		for(int i=0;i<v[x].size();i++){
//			if(!vis[v[x][i]])
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
//			v[a].push_back({j,t[i][j]});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		dfs(x,y);
		cout<<w[x]+w[y]+t[x][y]+t[x][y]+t[x][y]+t[x][y];
	}
	return 0;
}
