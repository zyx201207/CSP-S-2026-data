#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M = 5e5 + 110;
int w[M],x,y;
long long ans;
vector<int> a[1010],t[1010],id[M],pos[M];
vector<bool> vis[M];
void dfs(int u,int p,int q,long long s){
	if(u == y){
		ans = min(ans,s);
		return;
	}
	if(s > ans) return;
	if(q < a[p].size()-1 && p != -1){//Ô­Â·Ïß 
		dfs(a[p][q+1],p,q+1,s);
		vis[a[p][q+1]][p] = 1;
	}
	for(int i=0;i<id[u].size();i++){
		if(id[u][i] == p) continue;
		if(vis[u][i]) continue;
		vis[u][i] = 1;
		if(p != -1 && q != -1){
			dfs(u,id[u][i],pos[u][i],s+t[p][q]+t[id[u][i]][pos[u][i]]);
		}
		else dfs(u,id[u][i],pos[u][i],s+t[id[u][i]][pos[u][i]]);
	}
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	
	for(int i=1,k;i<=n;i++){
		cin >> k;
		for(int j=1,xx,yy;j<=k;j++){
			cin >> xx >> yy;
			a[i].push_back(xx);
			t[i].push_back(yy);
			id[xx].push_back(i);
			pos[xx].push_back(j-1);
		}
	}
	
	while(q--){
		cin >> x >> y;
		ans = 1e18;
		dfs(x,-1,-1,0);
		ans += (w[x] + w[y]);
		cout << ans << '\n';
	}
	
	
	
	
	
	return 0;
}
