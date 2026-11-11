#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long

LL read(){LL x; scanf("%lld", &x); return x; }
//signed read(){
//	signed x = 0;
//	char c = getchar();
//	while(c < '0' || c > '9')c = getchar();
//	while('0' <= c && c <= '9')x = x * 10ll + (c - '0'), c = getchar();
//	return x;
//}

const int N = 2e6 + 100;
const int V = 5e6 + 100;

int n, d;
int a[N];

int ans;

int f[N];
void calc(int l, int r){
//	cerr << "C:" << l << "," << r << "\n";
	
	if(r - l + 1 < 4)return ;
		
	for(int i = l; i <= r; i ++){
		for(int j = i; j <= r; j ++)f[j] = 0;
		f[i] = 1;
		int p = i, u = i, v = i, sf = f[i];
		while(1){
			while(v + 1 <= r && a[v + 1] - a[u] <= d)v ++;
			int t = p;
			for(int j = u + 1; j <= v; j ++){
				while(a[j] - a[t] > d)sf -= f[t], t ++;
				f[j] = sf;
			}
			sf = 0;
			for(int j = u + 1; j <= v; j ++){
				if(f[j] != 1 && f[j] != 2)f[j] = V;
				sf += f[j];
				if(f[j] == 2)ans ++;
			}
			p = u + 1; u = v;
			if(v == r)break;
		}
	}
}
void solve(){
	ans = 0;
	
	n = read(); d = read();
	for(int i = 1; i <= n; i ++)a[i] = read();

	int l = 1;
	for(int r = 1; r <= n; r ++){
		if(r + 1 == n + 1 || a[r + 1] - a[r] > d)calc(l, r), l = r + 1;			
	}
	
	printf("%lld\n", ans);
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int cid = read(), tii = read();
	
	for(int z = 1; z <= tii; z ++)solve();
	
	return 0;
}
