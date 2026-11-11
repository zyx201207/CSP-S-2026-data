#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n = 0, m = 0, cnt = 0, idx = 0;
    cin >> n >> m;
    vector<ll> cry(n + 1, LLONG_MAX);
    for (int i = 0; i < n; i++){
        cin >> cry[i];
    }
    sort(cry.begin(), cry.end());
    ll dv = 0;
    while (idx < n && m >= 0) {
        dv = cry[idx + 1] - cry[idx];
        if (dv > 0 && m >= dv * cnt){
            cnt++;
            m -= dv * cnt;
        } else if (dv == 0){
            cnt++;
        } else{
            cnt++;
            break;
        }
        idx++;
    }
    cout << cnt;
    return 0;
}