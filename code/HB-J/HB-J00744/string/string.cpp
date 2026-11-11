#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;


struct Node   {
    LL l;
    char c;
} a[N];

LL n, cnt;

int main() {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (LL i = 1; i<= n; i++)  cin >> a[i].l >> a[i].c;

    LL i = 1, j = n;
    while (i < j) {
        LL rec = min(a[i].l, a[j].l);
        bool f1 = 1, f2 = 1;
        a[i].l -= rec;
        a[j].l -= rec;

        if (a[i].c != a[j].c) cnt += rec;

        if (a[i].l != 0) f1 = 0;
        if (a[j].l != 0) f2 = 0;
        if (f1) i++;
        if (f2) j--;
    }
    cout << cnt << '\n';

    return 0;
}
