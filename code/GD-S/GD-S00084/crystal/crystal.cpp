#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //auto t = clock();
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n ;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, ans = 0;
    ll num = 0;
    for(int r = 1; r <= n; r++){
        num += (r - l) * (a[r] - a[r - 1]);
        while(l < r && num > m)
            num -= a[r] - a[l], l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    //cout << clock() - t;
}