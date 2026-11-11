#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, char> > p(n + 5);
    for(ll i = 1; i <= n; i ++) cin >> p[i].first >> p[i].second;
    ll l = 1, r = n;
    ll cl = p[1].first, cr = p[n].first, ans = 0;
    while (l < r){
        if(p[l].second != p[r].second) ans += min(cl, cr);
        if(cl < cr) {
            cr -= cl;
            cl = p[++ l].first;
        }
        else if(cl > cr) {
            cl -= cr;
            cr = p[-- r].first;
        }
        else if(cl == cr) {
            cr = p[-- r].first;
            cl = p[++ l].first;
        }
    }
    cout << ans << '\n';
    return 0;
}