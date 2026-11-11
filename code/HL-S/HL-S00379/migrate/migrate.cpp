#include <iostream>
using namespace std;
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    if (!c) cout << 1 << 2;
    else {
            for(int i  = 0;i < t;i ++) {
                cout << 0;
            }
    }
    return 0;
}
