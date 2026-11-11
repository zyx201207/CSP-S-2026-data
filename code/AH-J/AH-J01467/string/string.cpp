#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    long long x = 1,y = n;
    while (x < y) {
        if (a[x] == 0) {
            x++;
        }
        if (a[y] == 0) {
            y--;
        }
        if (b[x] != b[y]) {
            s++;
        }
        a[x]--;
        a[y]--;
    }
    cout << s;
    return 0;
}
