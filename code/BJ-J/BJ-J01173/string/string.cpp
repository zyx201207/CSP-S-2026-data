#include<bits/stdc++.h>
using namespace std;
int n, l, r;
long long ans, a[200010], b[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    l = 1;
    r = n;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> a[i] >> c;
        b[i] = c - '0';
    }
    while(l < r){
        if(b[l] != b[r]){
            ans += min(a[l], a[r]);
        }
        /*if(a[l] < a[r]){
            a[r] -= a[l];
            l++;
        }
        if(a[l] > a[r]){
            a[l] -= a[r];
            r--;
        }
        if(a[l] == a[r]){
            l++;
            r--;
        }*/
        long long x = min(a[l], a[r]);
        a[r] -= x;
        a[l] -= x;
        if(a[l] == 0) l += 1;
        if(a[r] == 0) r -= 1;
    }
    cout << ans;
    return 0;
}
