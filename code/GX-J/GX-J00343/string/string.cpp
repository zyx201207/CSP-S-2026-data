#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct zf {
    ll number;
    char c;
};

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<zf> p;
    p.reserve(n);
    for(int i = 0;i < n;i++) {
        ll sz;
        char z;
        cin >> sz >> z;
        if(!p.empty() && p.back().c == z) p[p.size() - 1].number += sz;
        else
            p.push_back({sz, z});
    }
    int L = 0, R = p.size() - 1, cz = 0;

    ll ans = 0;
    while(L < R) {
        //cz = abs(p[L].number - p[R].number);
        if(p[L].c != p[R].c) {
            ans += min(p[L].number, p[R].number);
            if(p[L].number < p[R].number) {
                p[R].number -= p[L].number;
                L++;
            } else if(p[R].number < p[L].number) {
                p[L].number -= p[R].number;
                R--;
            } else {
                L++, R--;
            }
        } else {
            if(p[L].number < p[R].number) {
                p[R].number -= p[L].number;
                L++;
            } else if(p[R].number < p[L].number) {
                p[L].number -= p[R].number;
                R--;
            }
             else L++, R--;
        }
    }
    cout << ans;
    return 0;
}
