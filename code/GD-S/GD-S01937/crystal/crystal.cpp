#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005];
queue<long long> q;
int main(){
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long x = 1, ans = -1;
	long long num = 0;
	while(x <= n){
		num += q.size() * (a[x] - a[x - 1]);
		q.push(a[x]);
		while(num > m){
			num -= a[x] - q.front();
			q.pop();
		}
		long long y = q.size();
		ans = max(ans, y);
//		cout << y << ' ' << num << endl;
		x++;
	}
	cout << ans;
} 
//5 5
//1 2 4 8 9
