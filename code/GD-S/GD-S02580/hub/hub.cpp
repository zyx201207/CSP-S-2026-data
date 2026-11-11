#include<bits/stdc++.h>
//#define int long long
using namespace std;
vector<int> v[1000005];
int ans = INT_MAX;
bool b[1000005],c[1000005];
int f[1000005][31],d[1000005];
int dis[4005][4005];
int n,k;
void init(){
	for(int i = 1;i <= n;i++) v[i].clear();
	memset(dis,0,sizeof(dis));
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	ans = INT_MAX;
}
void build(int x,int fa){
	f[x][0] = fa;
	d[x] = d[fa] + 1;
	for(auto k : v[x]){
		if(k == fa) continue;
		build(k,x);
	}
}
void clean(int x,int fa){
	c[x] = false;
	for(auto k : v[x]){
		if(k == fa || c[k] == 0) continue;
		clean(k,x);
	}
}
void dfs(int x,int rst){
	if(rst == 0 || x == n + 1){
		for(int i = 1;i <= n;i++){
			c[i] = b[i];
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(c[i]){
				clean(i,0);
				cnt++;
			}
		}
		if(cnt > 2 || cnt <= 0) return;
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if(b[i]) continue;
			int minn = INT_MAX;
			for(int j = 1;j <= n;j++){
				if(b[j]){
					minn = min(minn,dis[i][j]);
				}
			}
			sum = max(sum,minn);
		}
		if(ans > sum){
			ans = sum;
		}
		return;
	}
	if(n - x + 1 < rst) return;
	if(n - x + 1 == rst){
		b[x] = 1;
		dfs(x+1,rst-1);
		b[x] = 0;
		return;
	}
	b[x] = 1;
	dfs(x+1,rst-1);
	b[x] = 0;
	dfs(x+1,rst);
}
int lca(int x,int y){
	if(d[x] < d[y]){
		swap(x,y);
	}
	int cnt = 0;
	for(int i = 30;i >= 0;i--){
		if(d[f[x][i]] >= d[y]){
			x = f[x][i],cnt = cnt + pow(2,i);
		}
	}
	if(x == y) return cnt;
	for(int i = 30;i >= 0;i--){
		if(d[f[x][i]] != d[f[y][i]]) cnt = cnt + 2 * pow(2,i),x = f[x][i],y = f[y][i];
	}
	return cnt + 2;
}
void work(){
	cin >> n >> k;
	init();
	for(int i = 1;i < n;i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	build(1,0);
	for(int j = 1;j <= 30;j++){
		for(int i = 1;i <= n;i++){
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			dis[i][j] = dis[j][i] = lca(j,i);
		}
	}
	if(n <= 10){
		dfs(1,k);
		cout << ans;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		work();
		cout << endl;
	}
	return 0;
}

