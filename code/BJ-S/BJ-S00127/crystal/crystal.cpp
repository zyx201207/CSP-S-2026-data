#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e5+5;
ll n, m, ans, sum;
ll a[N];

bool is = true;

bool cmp(ll x, ll y){
    return x > y;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] - a[i - 1] != a[2] - a[1] && i > 2){
            is = false;
        }
    }
    if(is == true){
        cout << (m / (a[2] - a[1]));
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int l = 1; l <= n; l++){
        ll r = l;
        ll x = m;
        sum = 0;
        while(r <= n && (x - (a[l] - a[r])) > 0){
            x -= (a[l] - a[r]);
            r++;
            sum++;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
