#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, a[N];
char c[N];
ll ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while(l < r){
        if(a[l] == a[r]){
            if(c[l] != c[r]){
                ans += 1ll * a[l];
            }
            l++, r--;
        }else if(a[l] > a[r]){
            if(c[l] != c[r]){
                ans += 1ll * a[r];
            }
            a[l] -= a[r];
            r--;
        }else{// a[l] < a[r]
            if(c[l] != c[r]){
                ans += 1ll * a[l];
            }
            a[r] -= a[l];
            l++;      
        }
    }
    cout << ans;
    return 0;
}