#include <bits/stdc++.h>
using namespace  std;

int n = 0,sum = 0;
char asd[10000010];
int g[10000010];

int main () {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int num = 0;
    for (int i = 0;i < n;i++) {
        int a;
        char b;
        cin >> a >> b;
        g[i] = a;
        for (int j = 0;j < a;j++) {
            asd[num] = b;
            num++;
        }
    }
    bool ok = 1;
    for (int i = 0;i < n;i++) {
        if (asd[i] == asd[i + 1] && asd[i - 1] == asd[i]) {
            ok = 1;
        }
        else {
            ok = 0;
        }
    }
    if (ok == 1) {
        cout << 0;
        return 0;
    }
    int max1 = -1,min1 = 200005,w1 = 0,w2 = 0;
    for (int i = 0;i < num;i++) {
        if (max1 < g[i] && max1 != g[i]) {
            max1 = g[i];
            w1 = i;
        }
        if (min1 > g[i] && g[i] != 0) {
            min1 = g[i];
            w2 = i;
        }
    }
    cout << max1;
    return 0;
}
