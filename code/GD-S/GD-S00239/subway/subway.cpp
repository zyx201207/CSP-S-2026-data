#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,h,w[505],a[505][1005],t[505][1005],k,x,y;
struct g{
	int a,b;
};
vector<g> e[1005];
queue<g> q;
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>h;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back({i,j});
		}	
	}
	while(h--){
		cin>>x>>y;
		for(int i=0;i<e[x].size();i++){
			int ls=e[x][i].a,lt=e[x][i].b;
			cout<<ls<<" ";
			q.push({x,t[ls][lt]});
		}	
		cout<<"\n";
//		while(!q.empty()){
//			int u=q.front().a,s=q.front().b;
//			for(int i=0;i<e[u].size();i++){
//				int x=e[u][i];
//			}
//		}
	}
	return 0;
} 
