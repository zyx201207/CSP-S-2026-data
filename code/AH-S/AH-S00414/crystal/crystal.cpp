#include<bits/stdc++.h>
using namespace std;

const int N = 5e5;
int n;
long long m, tot, ans, a[N + 5];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	a[n + 1] = a[n];
	tot = m;
	for(long long i = n, j = n; i >= 1; i--){
		tot += (i - j + 1) * (a[i + 1] - a[i]);
		while(j && tot >= a[i] - a[j - 1]){
			tot -= (a[i] - a[j - 1]);
			j--;
		}
		ans = max(ans, i - j + 1);
		//cout << tot << " " << ans << "\n";
	}
	cout << ans;
	return 0;
}
