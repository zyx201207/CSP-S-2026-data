// 100 pts
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], n, m, cnt[31], ans, anshi = -1;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int p = 0;
		cin >> a[i];
		int tmp = a[i];
		while(tmp){
			cnt[p] += (tmp & 1);
			tmp >>= 1;
			p++;
		}
	}
	for(int i = 30;i;i--)
		if(cnt[i] >= m){
			anshi = i;
			break;
		}
	for(int i = 1;i <= n;i++) a[i] &= ((1 << (anshi + 1)) - 1);
	sort(a + 1, a + 1 + n);
	ans = a[n];
	for(int i = n - 1;i > n - m;i--) ans &= a[i];
	cout << ans;
	return 0;
}
