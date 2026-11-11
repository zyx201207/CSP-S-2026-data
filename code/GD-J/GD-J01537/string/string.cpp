#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
long long ans;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int i = 1, j = n;
	while(i < j){
		while(i < j && a[j] <= a[i]){
			a[i] -= a[j];
			if(c[i] != c[j]) ans += a[j];
			j--;
		}
		if(a[j] > a[i]){
			a[j] -= a[i];
			if(c[i] != c[j]) ans += a[i];
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}
