#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
int c, t, n, m, a[2000005], ans, flg;
struct node{
	int cnt, w;
}b[2000005];
stack<int> stk;
node merge(node a, node b){
	if(b.w + 1 < a.w){
		a = (node){b.cnt, b.w + 1};
	}else if(b.w + 1 == a.w){
		a.cnt += b.cnt;
	}
	return a;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t --){
		cin >> n >> m;
		ans = 0;
		flg = 1;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
			if(i > 2 && a[i] - a[i - 1] != a[2] - a[1]) flg = 0;
		}
		if(n <= 5000){
			for(int i = 1;i <= n;i ++){
				int l = i;
				b[i] = (node){1,0};
				for(int j = i + 1;j <= n;j ++) b[j] = (node){0, INF};
				for(int j = i + 1;j <= n;j ++){
					for(int k = l;k < j;k ++){
						if(a[j] - a[k] <= m) b[j] = merge(b[j], b[k]);
						else l ++;
					}
					if(b[j].cnt >= 2) ans = (ans + b[j].cnt * (b[j].cnt - 1) / 2);
				}
			}
			cout << ans << "\n";
		}else if(a[n] - a[1] <= m){
			cout << 0 << "\n";
		}else if (flg){
			int p = m / (a[2] - a[1]);
			if(p == 0) cout << 0 << endl;
			else{
				for(int i = p + 1;i <= n;i ++){
					if(i % 2 == 0){
						int l = i % p;
						ans += (i - l + 1) * (n - i + 1);
					}
				}
				cout << ans << "\n";
			}
		}
	}
	return 0;
}
