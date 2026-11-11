#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[200006],ans = 0,maxai;
int main() {
    freopen("and.in","r",stdin)
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i <= n;i++) {
        cin >> a[i];
        maxai = max(maxai,a[i]);
    }
    if (m == 1) ans = maxai;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}