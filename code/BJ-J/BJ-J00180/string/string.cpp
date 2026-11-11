#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll n, ans = 0;
deque<pair<int, char>> d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        int num; cin >> num;
        char ch; cin >> ch;
        d.push_front({num, ch});
    }
    while(d.size() > 1) {
        int a = d.front().first;
        char aa = d.front().second;
        d.pop_front();
        int b = d.back().first;
        char bb = d.back().second;
        d.pop_back();
        if(aa == bb) {
            if(a == b) {
                continue;
            }
            if(a < b) {
                d.push_back({b - a, bb});
            }
            if(a > b) {
                d.push_front({a - b, aa});
            }
        }
        else {
            if(a == b) {
                continue;
            }
            if(a < b) {
                ans += b - a;
                d.push_back({b - a, bb});
            }
            if(a > b) {
                ans += a - b;
                d.push_front({a - b, aa});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
