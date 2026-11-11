#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define N 505
#define M 500005
#define ll long long
#define INF (ll)1e18
#define PII pair<ll, ll>
#define lowbit(x) (x&(-x))

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0; ch=getchar(); }
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return (f?res:-res);
}
int c, n, m, d, Q, w[M], k[N];
ll dis[N][N], vis[N][N], a[N][N];
priority_queue<PII> q;
vector<PII> v[M];
void dij(int s){
	memset(dis[s], 0x3f, sizeof dis[s]);
	dis[s][s]=0;
	q.push({0, s});
	while(!q.empty()){
		int x=q.top().second; q.pop();
		if(vis[s][x]) continue;
		vis[s][x]=1;
		for(int y=1; y<=n; y++){
//			ll y=it.first, w=it.second;
			if(dis[s][y]>dis[s][x]+a[x][y]){
				dis[s][y]=dis[s][x]+a[x][y];
				q.push({-dis[s][y], y});
			}
		}
	}
}
int main(){
//	system("fc subway.out subway7.ans");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c=rd(), n=rd(), m=rd(), d=rd(), Q=rd();
	memset(a, 0x3f, sizeof a);
	for(int i=1; i<=m; i++) w[i]=rd();
	for(int i=1; i<=n; i++){
		k[i]=rd();
		for(int j=1; j<=k[i]; j++){
			ll u=rd(), t=rd();
			v[u].push_back({i, t});
		}
	}
	for(int i=1; i<=m; i++){
		for(PII itx:v[i]){
			for(PII ity:v[i]){
				ll x=itx.first, dx=itx.second;
				ll y=ity.first, dy=ity.second;
				a[x][y]=min(a[x][y], dx+dy), a[y][x]=min(a[y][x], dx+dy);
			}
		}
	}
	for(int s=1; s<=n; s++) dij(s);
//	for(int i=1; i<=n; i++, puts("")) for(int j=1; j<=n; j++) cout<<dis[i][j]<<' ';
	while(Q--){
		int s=rd(), t=rd();
		ll ans=INF;
		for(PII itx:v[s]){
			for(PII ity:v[t]){
				ll x=itx.first, dx=itx.second;
				ll y=ity.first, dy=ity.second;
				ans=min(ans, dx+dis[x][y]+dy+w[s]+w[t]);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
/*

*/

