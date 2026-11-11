#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e+6 + 6;
int nxt[maxn], prv[maxn], pre[maxn], suf[maxn];
ll a[maxn];

inline ll read() {
    ll ref = 0; bool f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = 0; ch = getchar();}
    while(isdigit(ch)) ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
    return f ? ref : -ref;
}

inline int rf(const int &L, const int &R, const ll &val) {
    int l = L, r = R;
    while(l < r) {
        int mid = l + r >> 1;
        if(a[R] - a[mid] > val) l = mid + 1;
        else r = mid;
    } return l;
}

inline int lf(const int &L, const int &R, const ll &val) {
    int l = L + 1, r = R + 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(a[mid] - a[L] <= val) l = mid + 1;
        else r = mid;
    } return l - 1;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c = read(), T = read();
    while(T--) {
        int n = read(); ll d = read(), answer = 0;
        for(int i = 1; i <= n; i++) a[i] = read(), pre[i] = suf[i] = 0;
        prv[1] = 1, nxt[n] = n;
        for(int i = 2; i <= n; i++) {
            prv[i] = prv[i - 1];
            while(a[i] - a[prv[i]] > d) prv[i]++;
            suf[prv[i]]++;
        }
        for(int i = n - 1; i; i--) {
            nxt[i] = nxt[i + 1];
            while(a[nxt[i]] - a[i] > d) nxt[i]--;
            pre[nxt[i]]++;
        }
        for(int i = 1; i <= n; i++) if(prv[nxt[i]] == i) pre[nxt[i]] += pre[i];
        for(int i = n; i; i--) if(nxt[prv[i]] == i) suf[prv[i]] += suf[i];
        //for(int i = 1; i <= n; i++) if(nxt[i] != i) pre[nxt[i]] += pre[i];
        //for(int i = n; i; i--) if(prv[i] != i) suf[prv[i]] += suf[i];
        //for(int i = 1; i <= n; i++) cout << prv[i] << ' ';cout << endl;
        //for(int i = 1; i <= n; i++) cout << nxt[i] << ' ';cout << endl;
        //for(int i = 1; i <= n; i++) cout << pre[i] << ' ';cout << endl;
        //for(int i = 1; i <= n; i++) cout << suf[i] << ' ';cout << endl;

        for(int i = 3; i < n; i++) {
            if(a[i] - a[i - 1] > d) continue;
            int L1 = rf(1, i - 1, d - a[i] + a[i - 1]), R1 = rf(1, i - 1, d - a[i + 1] + a[i - 1]) - 1;
            int L2 = lf(i, n, d - a[i] + a[i - 2]) + 1, R2 = lf(i, n, d - a[i] + a[i - 1]);
            if(L1 > R1 || L2 > R2) continue;
            answer += (ll)(pre[L1] + R1 - L1 + 1) * (R2 - L2 + suf[R2] + 1);
        } printf("%lld\n", answer);
    }

    return 0;
}


//1. 龙long
//2. 数组空间
//3. 手搓阳历
