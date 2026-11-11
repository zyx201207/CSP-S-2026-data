#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(a) \
(freopen(#a".in", "r", stdin),\
freopen(#a".out", "w", stdout))
const int N = 5e5+5;
int n, m, ans;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    file(crystal);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a+1, a+n+1);
    ll sum = 0;
    for(int i = 1, j = 1; i <= n; ++i){
        sum += (a[i] - a[i-1]) * (i - j);
        while(sum > m) sum -= a[i] - a[j++];
        ans = max(ans, i - j + 1);
    }

    cout << ans;
    return 0;
}
