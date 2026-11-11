#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct seg { int l, r; };
vector<seg> s[30];
int n, now = 0, ans = 0, a[30][N];
int bsl(int x, int id) {
    int l = 1, r = s[id].size() - 1, ans = s[id].size();
    while(l <= r) {
        int mid = l + (r - l >> 1);
        if(s[id][mid].r >= x) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
int bsr(int x, int id) {
    int l = 1, r = s[id].size() - 1, ans = 0;
    while(l <= r) {
        int mid = l + (r - l >> 1);
        if(s[id][mid].l <= x) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < 26; i++) {
        seg x; x.l = 0, x.r = 0;
        s[i].push_back(x); a[i][0] = 0;
    }
    for(int i = 1; i <= n; i++) {
        int x; char c;
        cin >> x >> c;
        seg tmp;
        tmp.l = now + 1; tmp.r = now + x;
        a[c - 'a'][s[c - 'a'].size()] = a[c - 'a'][s[c - 'a'].size() - 1] + x;
        s[c - 'a'].push_back(tmp);
        now += x;
    }
    for(int i = 0; i < 26; i++) {
        for(int j = 1; j < s[i].size(); j++) {
            int l = now - s[i][j].r + 1, r = now - s[i][j].l + 1;
            int x = bsl(l, i), y = bsr(r, i);
            ans += (x < y) * (a[i][y - 1] - a[i][x] + s[i][x].r - l + 1 + r - s[i][y].l + 1);
            ans += (x == y) * (min(r, s[i][x].r) - max(l, s[i][x].l) + 1);
        }
    }
    cout << (now - ans) / 2;
}

