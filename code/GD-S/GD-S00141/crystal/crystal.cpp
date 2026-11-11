#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m;
int ans;
ll a[N], pre[N], sel[N];
ll query(int l, int r){
	if(l == 1)
		return pre[r];
	return pre[r] - ((l - 1) * (a[r] - a[l]) + pre[l]);
}
bool check(int x, int l){
    if(query(l, x) <= m)
        return true;
    return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i < n; i++)
        pre[i + 1] += pre[i] + (a[i + 1] - a[i]) * i;
    for(int i = 1; i <= n; i++){
        int l = i + 1, r = n;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(mid, i))
                l = mid + 1;
            else
                r = mid - 1;
        }
        ans = max(ans, l - i);
    }
    cout << ans;
    return 0;
}

