#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int d[N];
signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
//	for (int i = 2; i <= n; i++) d[i] = a[i] - a[i - 1];
	int have = 1;
	int maxx = 1;
	int need = 0;
	int start = 1;
	for (int i = 2; i <= n; i++){
		need += have * (a[i] - a[i - 1]);
		have++;
		while(need > m){
			need -= a[i] - a[start];
			start++;
			have--;
		}
		maxx = max(maxx, have);
	}
	cout << maxx << endl;
	return 0;
}