#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int temp = a[1];
    for (int i = 0; i <= n; i++) {
        if (a[i] != temp && a[i] <= m) {
            cout << i << ' ';
            temp = a[i];
        }
    }
    return 0;
}