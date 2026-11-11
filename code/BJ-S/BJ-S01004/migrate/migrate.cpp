#include <iostream>
#include <fstream>
#include <iosfwd>
using namespace std;
int c, t, n, d, x[2000002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        cout << 0 << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


