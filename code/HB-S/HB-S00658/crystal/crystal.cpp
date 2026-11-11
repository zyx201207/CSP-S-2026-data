#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 10;
int n,m;
int a[N];
int bef[N];
int ans = 0;

bool check(int l,int r){
    if (a[r] * (r-l+1) - (bef[r] - bef[l-1]) <= m) {
        return true;
    }else return false;
}

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        bef[i] = bef[i-1] + a[i];
    }

    for (int i=n;i>=1;i--){
        int l = 1,r = i - 1,res = i;
        while (l <= r){
            int mid = (l+r) / 2;
            if (check(mid,i)){
                r = mid - 1;
                res = mid;
            }else l = mid + 1;
        }
        ans = max(ans,i-res+1);
    }
    cout << ans;

    return 0;
}
