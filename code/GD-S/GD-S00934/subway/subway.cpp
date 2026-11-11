#include<bits/stdc++.h>
using namespace std;
struct node{
	int y,w;
};
vector<node>g[600001];
int ans[600001];
bool vis[600001];
void digsktra(int s){
	priority_queue<int>q;
	vis[s]=true;
	while(!q.empty()){
		int x=q.top();q.pop();
		for(auto i:g[x]){
			int y=i.y,w=i.w;
			
		}
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			int y,w;
			cin >> y >> w;
			g[y].push_back({m+i,w});
			g[m+i].push_back({y,w});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		digsktra(x);
		cout << w[x]+w[y]+ans[y] << '\n';
	}
	return 0;
}
/*
一条线->一个点(m~n+m)
一个站厅->一个点(1~m)
一个站台到一个站厅->一条线 
*/
