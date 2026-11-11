#include <cstdio>
#include <cstring>
#include <queue>
#define N 505
#define M 500005
#define ll long long
using namespace std;

int c, n, m, d, q, x, y;
int wi[M], k[N];
vector<pair<int, int> > a[N], b[M];
//ai:地铁线路{经过节点，出入代价}
//bi:节点{经过线路，出入代价} 
ll e[N][N], f[N][N], s;
int i, j, l;
void RP(){
	#define inf 1000000000000000000
	ll rp = inf;
	rp++;
}
int main(){
	RP();
	memset(e, 0x3f, sizeof e);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(i=1; i<=m; i++)	scanf("%d", wi+i);
	for(i=1; i<=n; i++){
		scanf("%d", k+i);
		a[i].resize(k[i]);
		for(pair<int, int> &p:a[i]){
			scanf("%d%d", &p.first, &p.second);
			for(pair<int, int> q:b[p.first])	e[i][q.first] = min(e[i][q.first], 0ll+p.second+q.second);
			b[p.first].push_back({i, p.second});
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<i; j++)	e[i][j] = e[j][i] = min(e[i][j], e[j][i]);
		e[i][i] = 0;
	}
	memcpy(f, e, sizeof e);
	for(l=1; l<=n; l++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++)	f[i][j] = min(f[i][j], f[i][l]+f[l][j]);
		}
	}
	while(q--){
		scanf("%d%d", &x, &y);
		s = 1e18;
		for(pair<int, int> p:b[x]){
			for(pair<int, int> q:b[y]){
				s = min(s, f[p.first][q.first] + p.second + q.second);
			}
		}
		printf("%lld\n", s + wi[x] + wi[y]);
	}
	return 0;
}//xw
