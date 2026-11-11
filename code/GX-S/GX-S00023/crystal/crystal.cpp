#include <bits/stdc++.h>
using namespace std;
long long crl[500005],dif[500005],ans = 0;
long long erfen(long long x){
    long long l=1,r=x,mid;
    while (l < r){
        mid = (r+l)/2;
        if (mid*mid + mid >= x){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return r;
}
int main ()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> crl[i];
    }
    sort(crl+1,crl+n+1);
    for (int i = 1;i <= n;i++){
        dif[i] = crl[i] - crl[i-1];
    }
    for (int i = 1;i <n;i++){
        if (crl[i] != crl[i+1]){
            break;
        }
        if (i == n -1){
            cout << n;
            return 0;
        }
    }
    for (int i = 2;i < n;i++) {
        if (dif[i] != dif[i+1]){
            break;
        }
        if (i == n-1){
            m = m / dif[2] * 2;
            cout  << 1+erfen(m);
            return 0;
        }
    }
    long long total=0,am = 1;
    for (int i =2;i <= n;i++){
        if (dif[i] <= m){
            long long bian = i;
            while (total <= m && bian <=n){
                total += dif[bian] * am;
                am++;
                bian++;
            }
            ans = max(ans,am-1);
        }
    }
    cout << ans;
    return 0;
}
