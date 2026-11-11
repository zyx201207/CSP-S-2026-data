#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[500005];
ll an;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll befor = -1;
    for(ll i = n - 1;i >= 0;i--) {
        if(a[i] == a[i + 1] && i != n - 1) {
            continue;
        }
        ll k = m;
        ll place = i - 1;
        ll cnt = 1;
        while(k >= a[i] - a[place] && place >= 0) {
            cnt++;
            k -= a[i] - a[place];
            place--;
        }
        an = max(an, cnt);
    }
    cout << an << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
