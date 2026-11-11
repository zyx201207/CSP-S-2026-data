#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5,MAXM = 3e5;
int n,m;
ll mina;
ll a[MAXN],ans[MAXM];
ll pin[MAXM];
int main() {
    freopen("card.in","r",stdin)
    freopen("card.out","w",stdout);
    int x1 = 1;
    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) {
        if (a[i] < a[i - 1]) x1 = 0;
    }
    if (x1) {
        int j = 0;
        for (int i = 0;i < n;i++) {
            if (ans[a[i]] == 0) j += 1;
            ans[a[i]] += 1;
        }
    }
    for (int i = 0;i < m;i++) cout << ans[i] + ans[i - 1];
    for (int i = 0;i < m;i++) cout << ans[i] << " ";
    else {
        for (int i = 0;i < n;i++) {
            if (pin[a[i]]) pin[a[i]] = 0;
            pin[a[i]] += 1;
        }
        mina = min(pin[1],pin[2]);
        if (a[n] == 1) cout << n << " " << mina;
        else cout << mina << " " << n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}