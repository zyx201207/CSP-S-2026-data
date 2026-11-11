// string.cpp

#include <bits/stdc++.h>
using namespace std;


#define int ll
typedef long long ll;
const int N = 3e5 + 7;
ll l[N], r[N];
ll tl[N], tr[N];
char c[N], tc[N];

struct dat {
    ll l, r;
    char c;
    bool leaf;
} t[4*N];

void build(ll i, ll lb, ll rb) {
    if (lb == rb) {
        t[i].l = l[lb];
        t[i].r = r[lb];
        t[i].c = c[lb];
        t[i].leaf = 1;
        return;
    }

    ll mid = (lb + rb) >> 1;
    build(i<<1, lb, mid);
    build(i<<1|1, mid+1, rb);

    t[i].l = t[i<<1].l;
    t[i].r = t[i<<1|1].r;
    t[i].c = t[i<<1].c;
}

ll query(ll i, ll l, ll r, char c) {
    if (t[i].l > r || t[i].r < l) {
//        cout << "DUANLU() " << t[i].l << " " << l << " " << t[i].r << " " << r << endl;
        return 0;
    }

    if (!t[i].leaf) {
//        cout << endl << "distribute on " << t[i].l << " " << t[i].r << endl;
        return query(i<<1, l, r, c) + query(i<<1|1, l, r, c);
    }

    int cl = max(l, t[i].l);
    int cr = min(r, t[i].r);

//    cout << "catch up to " << t[i].l << " " << t[i].r << endl;
    if (c == t[i].c) return 0;
//    cout << "cost add " << cr - cl + 1 << endl;
    return cr - cl + 1;
}

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    // Here We Go!
    ll n;
    cin >> n;

    ll cur = 1, mid = -1;

    for (ll i = 1; i <= n; i++) {
        ll a;
        cin >> a >> tc[i];
        tl[i] = cur;
        tr[i] = cur + a - 1;

        cur += a;
    }

    int nb = 0;

    for (ll i = 1; i <= n; i++) {
        if (tl[i] <= (cur-1) / 2 && tr[i] > (cur-1) / 2) {
            c[++nb] = tc[i];
            l[nb] = tl[i];
            r[nb] = (cur-1) / 2;

            c[++nb] = tc[i];
            l[nb] = (cur-1) / 2 + 1;
            r[nb] = tr[i];
        } else {
            c[++nb] = tc[i];
            l[nb] = tl[i];
            r[nb] = tr[i];
        }
    }

    for (ll i = 1; i <= nb; i++) {
        if (r[i] >= (cur-1)/2) {
            mid = i;
            break;
        }
    }

//    cout << "$" << endl;
//    for (ll i = 1; i <= nb; i++) {
//        cout << r[i]-l[i]+1 << " " << c[i] << endl;
//    }
//    cout << "$" << endl;

//    cout << mid << " " << cur << endl;

    ll sz = pow(2, ceil(log2(nb)));

    for (ll i = nb+1; i <= sz; i++) {
        l[i] = r[i] = cur; // Virtual blocks
    }

    build(1, 1, sz);

    ll ans = 0;

    for (ll i = 1; i <= mid; i++) {
        ll al = cur-l[i], ar = cur-r[i];
        // cout << "query with " << al << " " << ar << endl;
        ans += query(1, min(al, ar), max(al, ar), c[i]);
    }

    cout << ans << endl;

}
