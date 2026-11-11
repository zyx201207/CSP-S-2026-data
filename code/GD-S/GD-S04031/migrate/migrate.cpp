#include <cstdio>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

typedef long long lld;
const int maxn = 2e6 + 5;
lld c, t, n, d, ans;
lld x[maxn];

int exi(int cor){
	auto a = upper_bound(x+1, x+1+n, cor);
	if(*(a-1) != cor) return -1;
	return a-1-x;
}

bool is2path(int u, int v){
	queue<pair<int, int> > q;
	q.push({u, 0});
	map<int, int> mp;
	int mi = 0x3f3f3f3f;
	while(!q.empty()){
		pair<int, int> t = q.front();
		int c = t.first, step = t.second;
		q.pop();
		if(c == v){
			mp[step]++;
			mi = min(mi, step);
			continue;
		}
		for(int i = 1; i <= d; i++){
			int tx = x[c] + i;
			int e = exi(tx);
			if(e == -1) continue;
			q.push({e, step+1});
		}
	}
	return mp[mi] == 2;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--){
		scanf("%lld%lld", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%lld", x+i);
		}
		if(11 <= c <= 12){
			lld dif = x[2] - x[1];
			if(d % dif != 0 || d == dif){
				printf("0\n");
				continue;
			}
			lld ti = d / dif;
			printf("%lld\n", max(0ll, n - 2 * ti + 1));
			continue;
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				ans += is2path(i, j);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
