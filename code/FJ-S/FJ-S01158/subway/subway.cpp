#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;

int c , n , m , d;
ll w[500005]; vector <pair <int , ll> > g[501005];

ll zbj[505][505];

int main(void){
	freopen("subway.out" , "w" , stdout);
	freopen("subway.in" , "r" , stdin);
	int qqq;
	scanf("%d%d%d%d%d" , &c , &n , &m , &d , &qqq);
	for(int i = 1;i <= m;i++) scanf("%lld" , &w[i]);
	for(int i = 1;i <= n;i++){
		int k; scanf("%d" , &k);
		while(k--){
			int a; ll t; scanf("%d%lld" , &a , &t);
			g[i + m].push_back({a , t});
			g[a].push_back({i + m , t});
		}
	}
	memset(zbj , 0x3f , sizeof(zbj));
	for(int i = 1;i <= n;i++){
		zbj[i][i] = 0;
		for(pair <int , ll> j : g[i + m])
			for(pair <int , ll> z : g[j.first])
				zbj[i][z.first - m] = min(zbj[i][z.first - m] , j.second + z.second);
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
				zbj[i][j] = min(zbj[i][j] , zbj[i][k] + zbj[k][j]);
	for(int i = 1;i <= qqq;i++){
		int s , t; scanf("%d%d" , &s , &t);
		ll ans = 1e18;
		for(pair <int , ll> i : g[s]) for(pair <int , ll> j : g[t])
			ans = min(ans , i.second + j.second + zbj[i.first - m][j.first - m]);
		printf("%lld\n" , ans + w[s] + w[t]);
	}
	return 0;
}
