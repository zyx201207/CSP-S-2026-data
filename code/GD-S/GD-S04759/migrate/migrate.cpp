#include <iostream>
using namespace std;

#define ll long long

const int N = 2 * 1e6 + 1;
ll pos[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--) {
        int n;
        ll d;
        cin >> n >> d;
        for(int i = 0; i < n; ++i) cin >> pos[i];
    }
    
    return 0;
}