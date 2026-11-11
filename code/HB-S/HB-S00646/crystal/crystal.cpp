#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500010], b[500010];

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for(int i=1; i<n; i++) b[i] += (a[i] - a[i-1]) * i;
    for(int i=1; i<n; i++) if(b[i] > m) cout << i;

    return 0;
}
