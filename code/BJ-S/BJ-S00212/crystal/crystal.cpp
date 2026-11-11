#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 20;
long long n, m, a[maxn];
bool check(long long x){
    long long sum = 0;
    for(long long i = 1; i <= x; i++)
        sum += a[x] - a[i];
    if(sum <= m) return true;
    for(long long i = 2; (i + x - 1) <= n; i++){
        sum -= (a[i + x - 2] - a[i - 1]);
        sum += (x - 1) * (a[i + x - 1] - a[i + x - 2]);
        if(sum <= m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    long long l = 1, r = n, mid, ans = 1;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
