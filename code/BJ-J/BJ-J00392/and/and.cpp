
#include <bits/stdc++.h>
using namespace std;

#define int long long

bitset<33> b[200005];
int a[200005];

struct vk {
    int id, v;
}p[200005];

signed main() {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    //cout << "read success: " << n << '\n';
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    if(m <= 1) {
        cout << 0;
        return 0;
    }

    sort(a + 1, a + n + 1, [](const int& x, const int& y) {
         return x  > y;});

    // 1000, 0111, 0101, 0110; 2;
    // 1000, 0111, 0110, 0101; 2;

    for(int i = 1; i <= n; i++) {
        b[i] = a[i];
        //cout << b[i].to_ullong() << '\n';
    }

    for(int mask = 30; mask >= 0; mask--) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(b[i][mask] == 1) {
                cnt++;
                // if(mask == 15) printf("debug: %ull\n", b[i].to_ullong());
            }
        }

        if(cnt >= m) {
            for(int i = 1; i <= n; i++) {
                p[i].id = i;
                if(b[i][mask] == 1) {
                    p[i].v = p[i].v * 2 + 1;
                } else {
                    p[i].v = p[i].v * 2;
                }
            }
        }
        //printf("mask:%lld cnt:%lld\n", mask, cnt);
    }

    sort(p + 1, p + n + 1,[](const vk& x, const vk& y) {
         return x.v > y.v; });

    int res = a[p[1].id];
    //printf("Debug: use %lld\n", a[p[1].id]);
    for(int i = 2; i <= m; i++) {
        //printf("Debug: use %lld\n", a[p[i].id]);

        res &= a[p[i].id];
    }
    cout << res;



    return 0;
}

