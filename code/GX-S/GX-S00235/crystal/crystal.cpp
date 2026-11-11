#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], sum[500010],f1 = 1, f2 = 1;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    for(int i = 0; i <= 500010; i++) sum[i] = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] += sum[i - 1] + a[i];
    int l = 1, r = 1, mx = 1;
    while(l <= r && r <= n){
        if((r - l + 1) * a[r] - (sum[r] - sum[l - 1]) <= m){
            mx = r - l + 1, r++;
        }
        else l++, r++;
    }
    cout << mx << "\n";
    return 0;
}
