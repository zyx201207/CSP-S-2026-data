#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005];

bool cmp(long long x, long long y){
	return x < y;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, ans = 0;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if(m <= 1e8){
		int q = 0;
		for(int i = 1; i <= n; i++){
			if(b[q] != a[i]){
				q++;
				b[q] = a[i];
			}
		}
		for(int i = 1; i <= q; i++){
			int s = 1;
			long long k = m;
			for(int j = i - 1; j >= 1; j--){
				k -= (a[i] - a[j]);
				if(k < 0){
					break;
				}else{
					s++;
				}
			}
			ans = max(s, ans);
		}
		cout << ans;
	}else{
		long long gc = a[2] - a[1];
		m /= gc;
		long long i = 1;
		while(m >= 0){
			m -= i;
			i++;
		}
		cout << i - 1;
	}
	return 0;
}
