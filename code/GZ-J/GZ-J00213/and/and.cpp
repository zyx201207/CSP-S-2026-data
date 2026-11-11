//GZ-J00213遵义市第四中学周高逸

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[200005], flag1=1, flag2=0;

ll lowbit(ll x){
    return (-x&x);
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    if(lowbit(n)==n) flag2 = 1;
    for(ll i=1; i<=n; ++i){
        cin >> a[i];
        if(lowbit(a[i]+1) != a[i]+1) flag1 = 0;
    }
    sort(a+1, a+n+1);

    if(flag1){
        cout << a[n-m+1];
        return 0;
    }

    if(m==1){
        cout << a[n];
        return 0;
    }
    else if(m==n){
        ll ans = a[1];
        for(int i=1; i<=n; i++){
            ans = (ans&a[i]);
        }
        cout << ans;
        return 0;
    }
    else if(m==2){
        ll ans = (a[1]&a[2]);
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n&&j!=i; ++j){
                ans = max(ans, (a[i]&a[j]));
            }
        }
        cout << ans;
        return 0;
    }
    else if(flag2){
        cout << 0;
        return 0;
    }
    else if(m<=20){
        ll ans = a[1];
        for(int i=n; i>=n-m+1; i++){
            ans = (ans&a[i]);
        }
        cout << ans;
        return 0;
    }

    return 0;
}
