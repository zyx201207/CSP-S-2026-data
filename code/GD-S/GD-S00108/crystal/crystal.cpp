#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w",stdout);
    ull n, m;
    cin >> n >> m;
    vector<ll> a(n), sum(n+1);

    if(m == 0){
        cout << 1;
        return 0;
    }
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    sum[0] = a[0];
    for(int i = 1;i < n;i++){
        sum[i] = a[i] + sum[i-1];
    }
    ll ans = 1;
    for(int i = 1;i < n;i++){
        if(i*a[i] - sum[i-1] > m){
            ans = i;
            break;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
}
