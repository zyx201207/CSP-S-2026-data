#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > f[500010];
long long g[510][510],w[500010];
int c,n,m,q,d;
int read(){
	int f = 1,x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1;i <= m;i++) w[i] = read();
	for(int i = 1;i <= n;i++){
		int k = read();
		for(int j = 1;j <= k;j++){
			int x = read(),t = read();
			f[x].push_back({i,t});
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i = 1;i <= n;i++) g[i][i] = 0;
	for(int i = 1;i <= m;i++){
		for(auto [x,wx] : f[i]){
			for(auto [y,wy] : f[i]){
				if(x == y) continue;
				g[y][x] = g[x][y] = min(g[x][y],wx * 1ll + wy * 1ll);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			for(int k = i;k <= j;k++){
				g[j][i] = g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
			}
		}
	}
	/*
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	while(q--){
		int x = read(),y = read();
		long long ans = 1e18;
		for(auto [i,ti] : f[x]){
			for(auto [j,tj] : f[y]){
				ans = min(ans,g[i][j] + w[x] + w[y] + ti + tj);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
