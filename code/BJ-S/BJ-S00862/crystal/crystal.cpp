#include<bits/stdc++.h>
using namespace std;

long long n, m, ans, a[500010], pre[500010];

long long cost(long long x, long long y){
    return a[x] * (x - y + 1ll) - (pre[x] - pre[y - 1ll]);
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(long long i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    for(long long i = 1; i <= n; i++){
        if(a[i] == a[i + 1] && i != n){
            continue;
        }
        long long l = 1, r = i;
        while(l < r){
            if(l == r - 1){
                if(cost(i, l) <= m){
                    r = l;
                }
                else{
                    l = r;
                }
                continue;
            }
            long long mid = (l + r) / 2;
            if(cost(i, mid) <= m){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}