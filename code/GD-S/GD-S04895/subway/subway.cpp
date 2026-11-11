#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5,maxn = 505;
long long c,n,m,d,q,t,sx,sy,k[maxn],ans,vis[N];
vector<vector<long long>> a;
struct node{
	long long tk,x;
	vector<long long> v;
} f[N];
struct sp{
	long long step,vis;
};
long long bfs(long long l,long long r){
	memset(vis,0,sizeof(vis));
	queue<sp> q;
	vis[l] = 1;
	q.push({1,l});
	while(!q.empty()){
		long long steps = q.front().step;
		long long viss = q.front().vis;
		q.pop();
		long long sh = f[viss].v.size();
		for(int i = 1;i < sh;i++){
			for(int j = 1;j <= k[f[viss].v[i]];j++){
				if(vis[a[f[viss].v[i]][j]] == 0){
					vis[a[f[viss].v[i]][j]] = steps + 1;
					if(a[f[viss].v[i]][j] == r){
						return vis[a[f[viss].v[i]][j]];
					}
					else q.push({vis[a[f[viss].v[i]][j]],a[f[viss].v[i]][j]});
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> f[i].tk;
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t;
			f[a[i][j]].v.push_back(i);
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> sx >> sy;
		long long p = bfs(sx,sy);
		ans = (p - 1) * 2 * t + f[sx].tk + f[sy].tk;
		cout << ans << endl;
	}
	return 0;
}
