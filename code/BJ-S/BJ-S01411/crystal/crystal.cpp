#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,ans = 1;
long long m;
int a[N];
long long q[N];
bool check(int x){
    bool ok = 0;
    for(int i = 1;i <= n; i++){
        if(i >= x && a[i] * x <= q[i] - q[i - x] + m){
            ok = 1;
        }
    }
    return ok;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        q[i] = q[i - 1] + a[i];
    }
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
