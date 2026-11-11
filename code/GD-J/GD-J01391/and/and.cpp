#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
int a[N], len[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, cnt = 0, mul = 1, num = 0;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		mul = 1;
		for(int j = 1 ; j <= 31 ; j++){
			if(a[i] < mul){
				len[i] = j - 1;
				cnt = max(cnt, j - 1);	
				break;
			}
			mul *= 2;
		}
	}
	for(int k = cnt ; k >= 0 ; k--){
		num = 0;
		for(int i = 1 ; i <= n ; i++){
			if(len[i] == k) num++;
		}
		sort(a + 1, a + n + 1);
		int ans = a[n];
		if(num >= m){
			for(int i = n - 1 ; i >= n - m + 1 ; i--){
				ans &= a[i];
			}
			cout << ans << endl;
			return 0;
		}
		if(num < m){
			for(int i = 1 ; i <= n ; i++){
				if(len[i] == k){
					a[i] = a[i] | (1 << k);
					for(int j = 1 ; j <= 31 ; j++){
						if(a[i] < mul){
							len[i] = j - 1;
							cnt = max(cnt, j - 1);	
							break;
						}
						mul *= 2;
					}
				}
			}
		}
	}
	return 0;
}

