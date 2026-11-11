#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ans, d[N], cha, sum[N], cnt[N];
bool f;
void innt(){
	for(int i = 1; i <= n; i++){
		cnt[i] = cnt[i - 1] + cha;
		sum[i] = sum[i - 1] + cnt[i];
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 2) cha = a[i] - a[i - 1];
		if(a[i] - a[i - 1] != cha && i > 2) f = 1;
	}
	sort(a + 1, a + 1 + n);
	if(f == 0){
		innt();
		for(int i = 1; i <= n; i++){
			if(sum[i] > m) {
				cout << i;
				return 0;
			}
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			int m1 = m;
			for(int j = i - 1; j >= 0; j--){
				if(m1 >= a[i] - a[j]) {
					m1 -= (a[i] - a[j]);
					d[i]++;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			ans = max(d[i], ans);
		}
		cout << ans + 1;
	}
	return 0;
}