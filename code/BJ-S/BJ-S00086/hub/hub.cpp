#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c,t;
    cin >> c >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        cout << (n / 2 + k / 2) / 4 + 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}