#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
using LL = long long;

constexpr int N = 2e6, MAX_N = N+5, LOG_N = 21, MAX_LOG_N = LOG_N+2;

int n, ll[MAX_N], rr[MAX_N];
LL d, x[MAX_N];

namespace try_5000 {
    pair<int, int> d[5001][5001];
    void run() {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                d[i][j].first = d[i][j].second = 0;
            }
        }
        for(int i = 1; i <= n; i ++) {
            d[i][i].first = 0;
            d[i][i].second = 1;
            for(int j = i+1; j <= n; j ++) {
                if(ll[j] <= i) {
                    d[i][j].first = 1;
                    d[i][j].second = 1;
                    continue;
                }
                if(ll[j] == j || d[i][ll[j]].first == -1) {
                    d[i][j].second = -1;
                    d[i][j].first = -1;
                    continue;
                }
                if(d[i][ll[j]].second == 3) {
                    d[i][j].second = 3;
                    continue;
                }
                if(ll[j] == j-1) {
                    d[i][j].first = d[i][j-1].first + 1;
                    d[i][j].second = d[i][j-1].second;
                    continue;
                }
                if(ll[j] == j-2) {
                    if(d[i][j-2].first == d[i][j-1].first) {
                        d[i][j].second = d[i][j-1].second + d[i][j-2].second;
                        d[i][j].first = d[i][j-1].first + 1;
                        if(d[i][j].second > 3) d[i][j].second = 3;
                    }
                    else {
                        d[i][j] = d[i][j-2];
                        d[i][j].first ++;
                    }
                    continue;
                }
                if(d[i][ll[j]].first == d[i][ll[j]+1].first && d[i][ll[j]].first == d[i][ll[j]+2].first) {
                    d[i][j].second = 3;
                    continue;
                }
                if(d[i][ll[j]].first == d[i][ll[j]+1].first) {
                    d[i][j].first = d[i][ll[j]].first + 1;
                    d[i][j].second = d[i][ll[j]].second + d[i][ll[j]+1].second;
                    if(d[i][j].second > 3) d[i][j].second = 3;
                    continue;
                }
                d[i][j] = d[i][ll[j]];
                d[i][j].first ++;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = i+1; j <= n; j ++) {
                if(d[i][j].second == 2) ++ ans;
            }
        }
        cout << ans << "\n";
    }
}

void solve(int Cases) {
    cin >> n >> d;
    bool isDelta = true;
    for(int i = 1; i <= n; i ++) {
        cin >> x[i];
        int l = 1, r = i, mid = 0;
        while(l < r) {
            mid = (l + r) >> 1;
            if(x[i] - x[mid] <= d) r = mid;
            else l = mid + 1;
        }
        ll[i] = l;
        if(i > 2 && x[i] - x[i-1] != x[i-1] - x[i-2]) isDelta = false;
    }
    for(int i = 1; i <= n; i ++) {
        int l = i, r = n, mid = 0;
        while(l < r) {
            mid = (l + r + 1) >> 1;
            if(x[mid] - x[i] <= d) l = mid;
            else r = mid-1;
        }
        rr[i] = mid;
    }
    if(isDelta) {
        if(ll[n] == 1) {
            cout << "0\n";
            return;
        }
        int ju = n - ll[n];
        if(ju == 0 || ju == 1) {
            cout << "0\n";
            return;
        }
        if(ju * 2 > n) {
            cout << "0\n";
            return;
        }
        cout << n - 2 * ju + 1 << "\n";
        return;
    }
    if(13 <= Cases && Cases <= 14) {
        LL ans = 0;
        for(int i = 1; i <= n; i ++) {
            if(ll[i] >= i-1) continue;
            int l = 1, r = ll[i]-1, mid = 0;
            while(l < r) {
                mid = (l + r) >> 1;
                if(rr[i] >= ll[i]+1) r = mid;
                else l = mid+1;
            }
            int L = l;
            l = 1, r = ll[i]-1;
            while(l < r) {
                mid = (l + r + 1) >> 1;
                if(rr[i] <= ll[i]+1) l = mid;
                else r = mid-1;
            }
            int R = l;
            //cout << "i = " << i << "  L = " << L << "  R = " << R << "\n";
            if(rr[L] == ll[i]+1 && L <= R) ans += R - L + 1;
        }
        cout << ans << "\n";
        return;
    }
    if(n <= 5000) { // ok
        try_5000::run();
        return;
    }
    return;
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while(t --) solve(c);
    return 0;
}

/*
0 1
10 2
1 2 3 4 5 6 7 8 9 10

4
*/

/*
13 1
8 10
-3 1 6 7 8 12 15 17

2
*/
