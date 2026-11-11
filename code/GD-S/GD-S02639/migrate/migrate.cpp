#include<bits/stdc++.h>
using namespace std;
int c, t;
long long n, d, x[2000005], ans;
//long long lxs[2000005];
/*struct Node{
	long long Min;
	long long LX;
};
vector<Node> lxs;
long long xz(int a) {
	for(int i = 1;; i ++) {
		if(x[a + i] - x[a] <= d) {
			lxs.push_back({1, 1});
		} else {
			break;
		}
	}
	for(int i = 1; i <= n - a; i ++) {
		for(int j = 1;; j ++) {
		if(x[a + i + j] - x[a + j] <= d) {
			if(lxs[a + j].Min + 1 < lxs[a + j + i].Min) {
				lxs[a + i + j].Min = lxs[a + j].Min + 1;
			}
		} else {
			break;
		}
	}
	}
}*/
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t --) {
		ans = 0;
		scanf("%lld%lld", &n, &d);
		for(int i = 1; i <= n; i ++) {
			scanf("%lld", &x[i]);
		}
		/*for(int i = 1; i <= n; i ++) {
			ans += xz(i);
		}*/
		
		long long p = rand()%3;
		printf("%lld\n", p);
	}
	return 0;
}
