#include <bits/stdc++.h>
using namespace std;

int n,m;
int asd[200010];
int dsa[200010];

int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> asd[i];
    }
    int num = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 1 + i;j < n;j++) {
            dsa[num] = asd[i] & asd[j];
            num++;
        }
    }
    int max1 = -1;
    for (int i = 0;i < n;i++) {
        if (max1 < dsa[i]) {
            max1 = dsa[i];
        }
    }
    cout << max1;
    return 0;
}
