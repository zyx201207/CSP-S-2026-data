#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], s[N];
int head, tail;
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	head = 0, tail = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++){
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
//	cout << ans << endl;
	for(int i = 1; i <= n; i ++){
		head ++;
		while(tail <= head  && (head - tail + 1) * a[head] - s[head] + s[tail - 1] > m) tail ++;
		ans = max(ans, head - tail + 1);
	}
	cout << ans << "\n";
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

