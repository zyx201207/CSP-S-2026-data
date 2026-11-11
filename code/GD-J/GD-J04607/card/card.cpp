#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N] , p[N] , cnt[N];
int main() {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n , m; cin >> n >> m;
	int fl = 1;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) fl = 0;
	}
	if (fl) {
		int pr = a[1] , cot = 1;
		for (int i = 1 ; i <= n ; i ++) {
			if (a[i] != pr) pr = a[i] , cot ++;
			cnt[cot] ++;
		}
		int sum = 0;
		for (int i = 1 ; i <= cot ; i ++) {
			sum += cnt[i];
			cout << sum << " ";
		}
		return 0;
	}
	for (int i = 1 ; i <= n ; i ++) {
		vector <int> p(m + 5 , 0);
		for (int j = i ; j <= n ; j ++) {
			if (p[a[j]] != 0) {
				for (int k = p[a[j]] ; k < j ; k ++) p[a[k]] = 0;
			}
			p[a[j]] = j;
		}
		for (int j = 1 ; j <= m ; j ++) if (p[j]) cnt[j] ++;
	}
	for (int i = 1 ; i <= m ; i ++) cout << cnt[i] << " ";
	return 0;
}
/*
10 2
2 1 2 1 1 2 2 1 2 2

40pts?
*/
