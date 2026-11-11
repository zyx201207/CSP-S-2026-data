#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
using ll = long long;
ll n,m,a[maxn],ans,sum[maxn];
bool check(int k){
    for(int i = 1;i + k - 1 <= n;i++){
        int l = i,r = i + k - 1;
        ll tmp = sum[r-1] - sum[l-1];
        ll cur = (k-1) * a[r] - tmp;
        if(cur <= m)return true;
    }
    return false;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)sum[i] = sum[i-1] + a[i];
    int l = 0,r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
