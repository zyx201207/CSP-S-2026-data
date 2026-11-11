#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans = 1,num,cnt,q,c[100005];
bool _ = 1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a,a+n);
    for (int i = 1;i < n;i++) if (_ && a[i] != a[i-1] + (a[1] - a[0])) _ = 0;
    if (_){
        ll nm = a[n-1];
        for (int i = n-2;i >= 0;i--){
            if (m < nm-a[i]) break;
            m -= nm - a[i];
            ans ++;
        }
        cout << ans;
        return 0;
    }
    for (int i = n-1;i >= 0;i--) num += abs(a[n-1] - a[i]);
    if (num <= m){
        cout << n;
        return 0;
    }
    num = 0,ans = 1,q = m;
    if (1 == 1){
        for (int i = n-1;i > 0;i--){
            if (ans > i) break;
            cnt = a[i],m = q,num = 1;
            for (int j = i - 1;j >= 0;j--){
                if (m < cnt-a[j]) break;
                m -= cnt - a[j],num++;
            }
            ans = max(ans,num);
        }
        cout << ans;
        return 0;
    }
    return 0;
}
