#include <cstring>
#include <iostream>
#include <algorithm>

#define endl '\n'
#define int long long
#define inf 0x3f3f3f3f
#define lnf 0x3f3f3f3f3f3f3f3f

using namespace std;

namespace luogu1038334_Ambrosia_guanzhuwo {
    const int N = 5e5 + 5;
    
    int n, m;
    int a[N];
    int q[N];
    int L, R, _Md;
    
    inline bool Check () {
        for (int i = n; i >= _Md; -- i) {
            if (a[i] * _Md - (q[i] - q[i - _Md]) <= m) {
                return 1;
            }
        }
        
        return 0;
    }
    
    void Main () {
        cin >> n >> m;
        
        for (int i = 1; i <= n; ++ i) {
            cin >> a[i];
        }
        
        sort (a + 1, a + n + 1);
        
        for (int i = 1; i <= n; ++ i) {
            q[i] = q[i - 1] + a[i];
        }
        
        L = 1;
        R = n;
        
        while (R > L) {
            _Md = (L + R + 1) >> 1;
            
            if (Check ()) {
                L = _Md;
            } else {
                R = _Md - 1;
            }
        }
        
        cout << L;
        return ;
    }
}

signed main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin.tie (nullptr) -> ios :: sync_with_stdio (false);

    int T = 1;
//    cin >> T;

    while (T --) {
        luogu1038334_Ambrosia_guanzhuwo :: Main ();
    }

    return 0;
}

