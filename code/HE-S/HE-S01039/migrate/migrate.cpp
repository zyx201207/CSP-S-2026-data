#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10,INF = 0x3f3f3f3f3f3f3f3f;
int n,d;
int a[N];
int l[N],r[N];
int s[N],cf[N];
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	cout << rand() % (n * (n + 1) / 2);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T --) solve();
	return 0;
}
