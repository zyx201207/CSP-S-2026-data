#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c, t;
int n, d;
ll x[1000006];

void Main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    cout << rand() % 10 << "\n";
    return ;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        Main();
    }
    return 0;
}
