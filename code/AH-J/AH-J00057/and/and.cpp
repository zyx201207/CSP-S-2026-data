#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m,ans = 0,x = 0;
    string a;
    cin >> n >> m;
    for (int i = 1;i <=n;i++){
        cin >> a[i];
    }
    for (int c = 1;c <= m;c++) {
        if (ans <= x) {
            ans == x;
        }
        for (int i = 1;i <= n-1;i++){
            for (int j = 2;j <= n;j++){
                x = a[i] & a[j];
            }
        }
    }
    cout << ans;
    return 0;
}
