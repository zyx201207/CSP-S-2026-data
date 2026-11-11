#include<bits/stdc++.h>
using namespace std;

long long dp[200010], a[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cout << a[m];

    return 0;
}
