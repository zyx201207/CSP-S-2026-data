#include <cstring>
#include <iostream>
#include <algorithm>

#define endl '\n'
#define int long long
#define inf 0x3f3f3f3f
#define lnf 0x3f3f3f3f3f3f3f3f

using namespace std;

namespace luogu1038334_Ambrosia_guanzhuwo {
    const int N = 2e6 + 5;
    
    int n, d;
    int a[N];
    int x, y;
    int _Ans;
    
    void Main () {
        cin >> n >> d;
        
        for (register int i = 1; i <= n; ++ i) {
            cin >> a[i];
        }
        
        x = a[2] - a[1];
        y = d / x;
        cout << (y > 1 ? max (n + 1 - 2 * y, 0ll) : 0) << endl;
        return ;
    }
}

signed main () {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin.tie (nullptr) -> ios :: sync_with_stdio (false);

    int c, T = 1;
    cin >> c >> T;

    while (T --) {
        luogu1038334_Ambrosia_guanzhuwo :: Main ();
    }

    return 0;
}

