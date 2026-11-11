#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 20;
int n, a[N];
long long ans;
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    int l = 1, r = n;
    while(l < r){
        if(c[l] == c[r]){
            if(a[l] < a[r]){
                a[r] -= a[l];
                a[l] = 0;
                l++;
            }else if(a[l] == a[r]){
                a[l] = 0;
                a[r] = 0;
                l++;
                r--;
            }else{
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }
        }else{
            if(a[l] < a[r]){
                ans += a[l];
                a[r] -= a[l];
                a[l] = 0;
                l++;
            }else if(a[l] == a[r]){
                ans += a[l];
                a[l] = 0;
                a[r] = 0;
                l++;
                r--;
            }else{
                ans += a[r];
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}