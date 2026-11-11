#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> v;
vector <int> soort(int l, int r){
    if (l > r) return {};
    if (l == r) return {v[l]};
    if (!(r - l - 1)){
        if (v[l] < v[r]) swap(v[l], v[r]);
        return {v[l], v[r]};
    }
    int m = (l + r) >> 1;
    auto v1 = soort(l, m), v2 = soort(m+1, r);
    auto it1 = v1.begin(), it2 = v2.begin();
    vector <int> vv(l - r + 1);
    while (it1 < v1.end() && it2 < v2.end()){
        if (*it1 > *it2){
            vv.push_back(*it1);
            it1++;
        }else{
            vv.push_back(*it2);
            it2++;
        }
    }
    while (it1 < v1.end()){vv.push_back(*it1); it1++;}
    while (it2 < v1.end()){vv.push_back(*it2); it2++;}
    for (int i = l; i <= r; i++) v[i] = vv[i];
    return vv;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    v = soort(0, n - 1);
    int ans = v[0];
    for (int i = 1; i < m; i++) ans &= v[i];
    cout << ans;
    return 0;
}
