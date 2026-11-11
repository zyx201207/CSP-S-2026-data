#include<bits/stdc++.h>
using namespace std;
int c, t, n;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t --)
    {
    	cin >> n;
    	int ans = 0, i = 0;
    	while(++i <= n-3) ans += i;
    	cout << ans << "\n";
	}
	return 0;
}

