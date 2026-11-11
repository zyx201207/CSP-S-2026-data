#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

const int N = 5 * 1e5 + 1; 
ll cs[N];
vector<ll> ds;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    ll m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> cs[i];

     sort(cs, cs + n);
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        ds.push_back(cs[i] - cs[i-1]);
        ll c = 0;
        for(int j = 0; j < i; ++j) c += (ds[j] * (j + 1));
        if(c <= m) ans = i + 1;
    }
    
    cout << ans << endl;
    return 0;
}
