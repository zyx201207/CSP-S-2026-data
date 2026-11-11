#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N], ans, n, m, k[N], f[35];
void dfs(int idx, int cnt, int sum){
	if(idx > n){
		if(cnt >= m) ans = max(ans, sum);
		return;
	}
	int t = a[idx];
	dfs(idx + 1, cnt, sum);
	dfs(idx + 1, cnt + 1, sum & t);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n <= 20){
		dfs(1, 0, 2147483647); 
		cout << ans;
	} 
	else if(n > 20 && n <= 2000){
		if(m == 1){
			sort(a + 1, a + 1 + n);
			cout << a[n];
		}
		else if(m == 2){
			int p, q, mx = 0;
			for(int i = 1; i <= n; i ++){
				for(int j = i + 1; j <= n; j ++){
					if(mx < (a[i] & a[j])){
						mx = a[i] & a[j];
						p = i, q = j;
					}
				}
			}
			cout << mx;
		}
		else if(m == n){
			int s = a[1];
			for(int i = 2; i <= n; i ++) s = s & a[i];
			cout << s;
		}
	}
	else{
		f[0] = 1;
		for(int i = 1; i <= 30; i ++) f[i] = f[i-1] * 2;
		bool ida = 1; int maxn = 0;
		for(int i = 1; i <= n; i ++)
			maxn = max(maxn, a[i]);
		if(maxn < 4){
			int q = 0, c = 0, cc = 0, ccc = 0;
			for(int i = 1; i <= n; i ++){
				if(a[i] == 0) q ++;
				else if(a[i] == 1) c ++;
				else if(a[i] == 2) cc ++;
				else ccc ++;
			}
			int g = m - ccc;
			if(c + cc + ccc < m) {
				cout << 0;
			}
			else{
				if(g <= 0) cout << 3;
				else{
					m -= ccc;
					if(g <= cc) cout << 2;
					else{
						if(g <= c) cout << 1;
						else cout << 0;
					}
				}
			}
		}
		else{
			for(int i = 1; i <= n; i ++){
				bool op = 0;
				for(int j = 0; j <= 30; j ++){
					if(a[i] == (f[j] - 1)){
						op = 1;
						break;
					}
				}
				if(op == 0) {
					ida = 0;
					break;
				}
			}
			if(ida == 1){
				sort(a + 1, a + 1 + n);
				int s2 = a[n];
				for(int i = n - 1; i >= n - m + 1; i --)
					s2 = s2 & a[i];
				cout << s2;
			}
			else{
				sort(a + 1, a + 1 + n);
				int s4 = a[n];
				for(int i = n - 1; i >= n - m + 1; i --)
					s4 = s4 & a[i];
				cout << s4;
			}
		}
		
	}
	return 0;
} 
