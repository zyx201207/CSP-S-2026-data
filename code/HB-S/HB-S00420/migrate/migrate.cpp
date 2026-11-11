#include<bits/stdc++.h>
using namespace std;
long long n, m, a[2000005];
int ans;
int T, c, k, t;
void solve1(int m){
	int d = a[2] - a[1];
	k = floor(m / d);
	if(k <= 1)return;
	t = 2 * k;
	ans = n - t + 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while(T--){
        cin >> n >> m;
        ans = 0;
        for(int i = 1; i <= n; i++)cin >> a[i];
        solve1(m);
        cout << max(ans, 0) << "\n";
    }
    return 0;
}
