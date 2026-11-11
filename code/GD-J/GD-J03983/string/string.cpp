#include <bits/stdc++.h> 
using namespace std;
long long a[210000];
char c[210000];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	long long suml = a[1];
	long long sumr = a[n];
	long long ans = 0;
	long long d = min(a[1], a[n]);
	for (int i = 1, j = n; i <= n && j >= 1; ){
		if (c[i] != c[j]){
			ans += d;
		}
		if (suml == sumr){
			i++;
			j--;
			d = min(a[i], a[j]);
			suml += a[i];
			sumr += a[j];
		}
		else if (suml < sumr){
			i++;
			d = min(a[i], sumr - suml);
			suml += a[i];
		}
		else{
			j--;
			d = min(a[j], suml - sumr);
			sumr += a[j];
		}
	}
	cout << ans / 2 << '\n';
	return 0;
}
