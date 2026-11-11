#include<bits/stdc++.h>
using namespace std;
long long n, m, mn = 99999999999, mx = 0, tp, ans = 1, p = 1, da = 0, jia = 0;
long long a[500005], ans2[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i + 1]){
			jia = 1;
		}
	}
	long long po = 1;
	for(int i = 1; i <= m + 1; i++){
		ans = 1;
		long long jil = 0;
		for(int j = 1; j < n; j++){
			jil = a[1];
			if(a[j] == a[j + 1] && a[j] == jil){
				jil = a[j];
				ans++;
			}
		}
		ans2[po++] = ans;
		da = m - i;
		if(a[p] == a[p + 2]){
			a[p + 2]++;
			p++;
			continue;
		}
		if(a[p] == a[p + 1]){
			a[p + 1]++;
		}else{
			a[p]++;
		}
	}
	for(int i = 1; i <= m + 1; i++){
		mx = max(mx, ans2[i]);
	}
	cout << mx + jia;
	return 0;
}
