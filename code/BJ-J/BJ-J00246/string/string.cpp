#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200005] = {};
    char c[200005] = {};
    long long n,ans = 0;;
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    long long l = 1,r = n;
    while(l < r){
        if(c[l] != c[r]){
            if(a[l] > a[r]){
                ans += a[r];
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }else if(a[l] < a[r]){
                ans += a[l];
                a[r] -= a[l];
                a[l] = 0;
                l++;
            }else{
                ans += a[l];
                a[l] = 0;
                a[r] = 0;
                l++,r--;
            }
        }else{
            if(a[l] > a[r]){
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }else if(a[l] < a[r]){
                a[r] -= a[l];
                a[l] = 0;
                l++;
            }else{
                a[l] = 0;
                a[r] = 0;
                l++,r--;
            }
        }
    }
    cout << ans;
    return 0;
}
