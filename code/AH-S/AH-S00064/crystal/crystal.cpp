#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m;
int main(){
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin >> n >> m;
    for (long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort (a+1,a+n+1);
    long long t = a[(n+1)/2];
    if (t - a[1] <= a[n] - t){
        for (long long i = (n+1)/2;i >= 1;i--){
            if (t-a[i] <= m){
                m-=t-a[i];
                a[i] = t;
            }
            if (m<=0){
                break;
            }
        }
    }
    else{
        for (long long i = n;i >= (n+1)/2;i--){
            if (a[i] - t <= m){
                m-=a[i]-t;
                a[i]=t;
            }
            if (m <= 0){
                break;
            }
        }
    }
    long long ans=0;
    for (long long i = 1;i <= n;i++){
        if (a[i] == t){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
