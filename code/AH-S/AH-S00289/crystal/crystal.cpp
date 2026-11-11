#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, l, r, mid, pos, ans = 1;
long long m, len, a[N], sum[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 2; i <= n; i++){
        l = 1, r = i - 1, pos = -1;
        while(l <= r){
            mid = (l + r) / 2;
            len = i - mid;
            long long x = len * a[i] - (sum[i - 1] - sum[mid - 1]);
            if(x <= m){
                r = mid - 1;
                pos = mid;
            }else{
                l = mid + 1;
            }
        }
        if(pos != -1){
            ans = max(ans, i - pos + 1);
        }
    }
    cout << ans;
    return 0;
}
