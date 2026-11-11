#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long gc = 0;
bool b = 1;
long long ma = LONG_LONG_MIN, mi = LONG_LONG_MAX;
int fi(long long val){
    int l = 1, r = n;
    int wz = 0;
    while(l <= r){
       int mid = (l + r) / 2;
       if(a[mid] <=  val){
            wz = max(wz, mid);
            l = mid + 1;
       }
       else{
            r = mid - 1;
       }
    }
    return wz;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ma = a[n];
    mi = a[1];
    long long x = a[2] - a[1];
    gc = x;
    for(int i = 3;i <= n; i++){
        long long h = a[i] - a[i - 1];
        if(h != gc){
            b = 0;
            break;
        }
    }
    if(b){
        int cnt = 0;
        for(int i = n - 1; i >= 1; i--){
            if(a[n] - a[i] > m) break;
            cnt++;
            m -= (a[n] - a[i]);
        }
        cout << cnt + 1 << '\n';
        return 0;
    }
    else{
        int ans = 0;
        for(int i = mi;i <= ma; i++){
            int en = fi(i);
            int cnt = 0;
            int u = m;
            for(int j = en;j >= 1; j--){
                if(i - a[j] > u) break;
                cnt++;
                u -= (i - a[j]);
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}
