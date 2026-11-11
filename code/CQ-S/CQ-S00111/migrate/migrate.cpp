#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
int n, m, c, t, tot, a[N], s[N], ans, d[N], f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> m; 
		memset(s, 0, sizeof(s));
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		tot = 1;
		for(int i = 2; i <= n; i ++){
			while((a[i] - a[tot] > m) && tot < i - 1){
				s[tot + 1] = max(0, s[tot ++] - 1);
			}
			if(a[i] - a[tot] <= m){
				s[tot] ++;
			}
		}
			while(tot < n - 1){
				s[tot + 1] = max(0, s[tot ++] - 1);
			}
//		for(int i = 1; i <= n; i ++){   
//			cout << s[i] <<" ";
//		}
		ans = 0;
		for(int	k = 1; k <= n; k ++){
		memset(f, 0x3f3f3f3f, sizeof(f));
		memset(d, 0, sizeof(d));
		d[k] = 1;
		f[k] = 0;
			for(int i = k; i <= n; i ++){
				for(int j = 1; j <= s[i] && i + j <= n; j ++){
					if(f[i + j] == f[i] + 1){
						d[i + j] += d[i];
					}
					if(f[i + j] > f[i] + 1){
						f[i + j] = f[i] + 1;
						d[i + j] = d[i];
					}
				}
			}
			for(int i = 1; i <= n; i ++){
				if(d[i] == 2) ans ++;
			}
			if(f[n] <= 2){
				ans = 0;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
/*
还剩15min码出这陀屎山的我不知道该怎么办了 
*/
