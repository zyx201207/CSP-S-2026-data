#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
#define int long long
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int N = 2e6 + 5;

int n;
int d;
int a[N];
int p[N];

int cnt = 0;
int minn = INF;
void dfs(int u, int l, int r, int p){
	if(u > r) return;
	if(u == r){
		if(minn == p) cnt++;
		if(minn > p){
			minn = p;
			cnt = 1;
		}
		return ;
	}
	
	rep(i,1,d,1){
		dfs(u + i, l, r, p + 1);
	}
	return;
}

void solve(){
	cin >> n >> d;
	rep(i,1,n,1){
		cin >> a[i];
	}
	int ans = 0;
	rep(len, d + 1, n, 1){
		rep(l, 1, n - len + 1, 1){
			int r = l + len - 1;
			cnt = 0;
			minn = INF;
			dfs(a[l], a[l], a[r], 0);
//			printf("%d -> %d --- %d\n",l,r,minn);
			if(cnt == 2) {
				ans++; 
//				printf("ans%d : %d - %d\n", ans, l , r);
			}
		}
	}
	cout << ans << endl;
}

signed main(){

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int c, T;
	cin >> c >> T;
	while(T--){
		solve();
	}
//	solve();
	return 0;
}








