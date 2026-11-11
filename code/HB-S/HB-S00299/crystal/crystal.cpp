#include <bits/stdc++.h>
using namespace std;
int n, m, ans = -1;
vector <int> v;
int calc(int tar){
    auto it = find(v.begin(), v.end(), tar);
    int sum = 0, crystal = 0;
    _:;
    if (it >= v.end()) return crystal;
    if (sum + abs(*it - tar) <= m){
        sum += abs(*it - tar);
        ++crystal;
    }
    it++;
    goto _;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), [](int _, int __){return _ > __;});
    for (int i = n-1; i >= 0; i--) ans = max(ans, calc(v[i]));
    cout << ans;
    return 0;
}
