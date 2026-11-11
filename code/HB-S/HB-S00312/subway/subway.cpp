#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;
typedef long long ll;
ll idx;
ll n, m, d, q; // n tielu/ge/shu  m ditiekou/ge/shu d zhantai/zuida/rongliang q wenti
// vector<ll> w;
// vector<vector<ll> > a, t;
// vector<vector<ll> > in;
// vector<vector<vector<pair<ll, ll> > > > e;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> idx >> n >> m >> d >> q;
    srand(time(0));
    // if(7 <= idx <= 11) {
    // w.resize(m + 5, 0);
    // a.resize(d);
    // t.resize(d);
    // e.resize(n, vector<pair<ll, ll> >());
    // for(ll i = 1; i <= m; i ++) cin >> w[i];
    // for(ll i = 0; i < d; i ++) {
    //     ll x;
    //     cin >> x;
    //     a[i].resize(x);
    //     t[i].resize(x);
    //     for(ll j = 0; j < x; j ++)
    //         cin >> a[i][j] >> t[i][j];
    //     if(x == 2) {
    //         e[a[i][0]][a[i][1]].emplace_back(t[i][0] + t[i][1], i);
    //         e[a[i][1]][a[i][0]].emplace_back(t[i][0] + t[i][1], i);
    //     }
    // }
    // while (q --) {
    //     ll s, e;
    //     cin >> s >> e;
    // }
    // }
    // w.resize(m + 5, 0);
    // a.resize(d);
    // t.resize(d);
    // for(ll i = 1; i <= m; i ++) cin >> w[i];
    // for(ll i = 0; i < d; i ++) {
    //     ll x;
    //     cin >> x;
    //     a[i].resize(x);
    //     t[i].resize(x);
    //     for(ll j = 0; j < x; j ++){
    //         cin >> a[i][j] >> t[i][j];
    //         in[a[i][j]].push_back(i);
    //     }
    // }
    // while (q --) {
    //     ll s, e;
    //     cin >> s >> e;
    //     cout << rand() % rand() << '\n';
    // }
    while (q --) cout << rand() % rand() << '\n';
    return 0;
}