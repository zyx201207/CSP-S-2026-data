#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int maxn = 5 * 1e5 + 5;
long long sum[maxn];
long long a[maxn];
long long ans;
long long total_ans;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	set<int>s;
	long long d = 0;
	for(int i = 1; i <= n - 1; i++) {
		d = a[i + 1] - a[i];
		s.insert(d);

	}
	if(s.size() == 1) {
		for(int i = 2; i <= 1e5 + 5; i++) {
			if(i * (i - 1) / 2 <= m / d && m / d <= i * (i + 1) / 2) {
				cout << i << endl;
				return 0;
			}
		}

   }
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++) { 
		ans = 0;
		for(int j = i - 1; j >= 1; j--) {
			ans += (a[i] - a[j]);
			if(ans <= m && (i - j + 1) > total_ans) total_ans = i - j + 1;
			else if(ans > m) break;
		}
	}
	cout << total_ans << endl;
	return 0;
}
