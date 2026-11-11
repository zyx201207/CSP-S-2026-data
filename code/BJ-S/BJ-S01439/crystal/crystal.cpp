/*
How many crystals can Xiao R use to create a big crystal.
Sort.
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m, temp;
ll a[500010];
ll b[500010];
ll s[500010];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    temp = a[(n + 1) / 2];

    for(ll i = 1; i <= n; i++) b[i] = abs(a[i] - temp);

    sort(b + 1, b + n + 1);

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + b[i];


    if(s[1] > m){
        cout << 1;
        return 0;
    }

    for(int i = 2; i <= n; i++){
        if(s[i] > m){
            cout << i - 1;
            return 0;
        }
    }

    cout << n;

    return 0;
}
