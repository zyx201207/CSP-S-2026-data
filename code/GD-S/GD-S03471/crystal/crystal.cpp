#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
long long n, m;
long long a[500900];
long long suma[500900];
long long Fans=0;
queue<long long> Q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) suma[i] = suma[i-1] + a[i];
	for (int i = 1; i <= n; i++){
		Q.push(i);
		while (!Q.empty() and a[i] * Q.size() - (suma[i] - suma[Q.front()-1]) > m) Q.pop();
		Fans = max(Fans, (long long)Q.size());
	}
	cout << Fans;
	
	return 0;

}
