#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010][30], b[30], s;
bool f[30];

int main() {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        long long x;
        cin >> x;
        for(int j=0; j<30; j++, x/=2) if(x % 2) a[i][j]++, b[j]++;
    }
    for(int i=29; i>=0; i--) {
        if(b[i] >= m) {
            for(int j=0; j<n; j++) if(!a[j][i]) f[j] = 1;
        }
        for(int i=0; i<30; i++) b[i] = 0;
        for(int i=0; i<n; i++) {
            if(f[i]) continue;
            for(int j=0; j<30; j++) if(a[i][j]) b[j]++;
        }
    }
    for(int i=0; i<30; i++) if(b[i] >= m) s += pow(2, i);
    cout << s;

    return 0;
}
