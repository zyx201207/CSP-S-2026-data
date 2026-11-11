#include<bits/stdc++.h>
using namespace std;
long long a , b , c , d , e , tk[505] , k , z[505] , x , y , ans;
map<pair<long long , long long> , long long> zt;
struct t{
	long long id , l;
}fa[505];
int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> a >> b >> c >> d >> e;
	for(long long i = 1;i <= c;i++) cin >> tk[i];
	for(long long i = 1;i <= b;i++) {
		cin >> k;
		long long h;
		for(long long j = 1;j <= k;j++) {
			cin >> z[j];
			cin >> h;
			zt[{i , z[j]}] = h;
			if(j > 1) {
				fa[z[j]].id = z[j - 1];
				fa[z[j]].l = i;
			}
		}
	}
	for(long long i = 1;i <= e;i++) {
		cin >> x >> y;
		ans = 0;
		ans += zt[{fa[y].l , y}] + tk[y];
		long long ll = fa[y].l;
		while(y != x) {
			if(fa[y].l != ll) {
				ans += zt[{ll , y}] + zt[{fa[y].l , ll}];
				ll = fa[y].l;
			}
			y = fa[y].id;
		}
		ans += zt[{ll , y}] + tk[y];
		cout << ans << "\n";
	}
	return 0;
}
