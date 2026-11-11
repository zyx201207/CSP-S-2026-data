#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
ll a[maxn];
bool cmp(ll x, ll y){
    return x > y;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n, ans = INT_MIN;
    ll m;
    bool f = 1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	if(i > 2 && a[i] - a[i-1] != a[i-1] - a[i-2]) f = 0;
    	if(i != 1 && a[i] - a[i-1] == 0) f = 0;
	} 
	if(f == 1){
		int pos = -1;
		sort(a + 1, a + n + 1);
		int gc = a[2] - a[1];
		for(int i = 1; i <= n; i++){
			if((gc + (i - 1) * gc) * (i - 1) / 2 > m){
				pos = i - 1;
				break;
			}
		}
		int xx = (gc + (n - 1) * gc) * (n - 1) / 2 - m;
		if(xx == 0){
			cout << n;
			return 0;
		}
		if(pos == -1 && xx % n != 0) pos = n - 1;
		cout << pos;
		return 0;
	}
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        ll sum = 0, t = m;
        int cnt = 1;
        for(int j = i + 1; j <= n; j++){
            if(t >= a[i] - a[j]) t -= (a[i] - a[j]), cnt++;
            else break;
        }
        if(t > 0 && i == 1 && t % n != 0) cnt--;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}

