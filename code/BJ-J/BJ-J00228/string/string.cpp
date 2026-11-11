#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
long long n, L, ans, cnt, mid, a[maxn];
char c[maxn];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        L += a[i];
    }
    mid = (L + 1) / 2;
    int l = 1, r = n, l_now = 0, r_now = 0;
    while(l != r && cnt != mid){
        if(a[l] == 0) l++;
        if(a[r] == 0) r--;
        if(a[l] == a[r]){
            cnt += a[l];
            if(c[l] != c[r]) ans += a[l];
            a[l] = a[r] = 0;
            l++; r--;
        }
        else if(a[l] > a[r]){
            cnt += a[r];
            if(c[l] != c[r]) ans += a[r];
            a[l] -= a[r]; a[r] = 0; r--;
        }
        else{
            cnt += a[l];
            if(c[l] != c[r]) ans += a[l];
            a[r] -= a[l]; a[l] = 0; l++;
        }
    }
    cout << ans << endl;
    return 0;
}
