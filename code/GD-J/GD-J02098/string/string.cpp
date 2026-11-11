#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],l,r,ans;
char c[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (ll i = 0;i < n;i++) cin >> a[i] >> c[i];
    l = 0,r = n-1;
    while (1){
        if (l >= r) break;
        if (c[l] != c[r]){
            if (a[l] > a[r]) ans += a[r],a[l] -= a[r],a[r] = 0,r --;
            else if (a[l] < a[r]) ans += a[l],a[r] -= a[l],a[l] = 0,l++;
            else ans += a[l],a[l] = 0,a[r] = 0,l ++,r --;
        }
        else{
            if (a[l] > a[r]) a[l] -= a[r],a[r] = 0,r --;
            else if (a[l] < a[r]) a[r] -= a[l],a[l] = 0,l++;
            else a[l] = 0,a[r] = 0,l ++,r --;
        }
    }
    cout << ans;
    return 0;
}

