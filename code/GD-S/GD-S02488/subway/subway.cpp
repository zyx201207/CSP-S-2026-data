#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;

int c,n,m,D,Q, w[N],k[501],a[N],t;
vector<int> st[N];
int q[N],f,r,d[N];

int bfs(int u,int v){
	q[++r] = u;
	d[u] = t;
	f = 1;
	while(f<=r){
		int x = q[f++];
		for(auto y: st[x]){
			q[++r] = y;
			d[y] = d[x] + t;
		}
	}
	return d[v];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[j],&t);
			st[a[j-1]].push_back(a[j]);
			st[a[j]].push_back(a[j-1]);
		}
	}
	for(int i=1;i<=Q;i++){
		int u,v,ans = 0;
		cin >> u >> v;
		ans += w[u] + w[v];
		ans += bfs(u,v);
		cout << ans << endl; 
	}
	
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 2 2 2 4 2
3 2 2 3 2 5 2
1 3
1 2

*/
/*
cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[i][j],&t[i][j]);
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin >> u >> v;
	}
*/
