#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define inf 0x3f3f3f3f
#define lnf 0x3f3f3f3f3f3f3f3f

using namespace std;

namespace luogu1038334_Ambrosia_guanzhuwo {
    const int N = 500 + 5, M = 5e5 + 5;
    
    int c, n, m, d, q;
    int w[M];
    int k;
    int a, t;
    vector <pair <int, int>> _Mp[M + N];
    int x, y;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> _Q;
    int _Dst[M + N];
    bool _Flg[M + N];
    pair <int, int> u;
    
    void BFS () {
        while (_Q.size ()) {
            _Q.pop ();
        }
        
        for (register int i = 0; i <= m + n; ++ i) {
            _Flg[i] = 0;
            _Dst[i] = lnf;
        }
        
        _Dst[x] = 0;
        _Q.push (pair <int, int> {0, x});
        
        while (_Q.size ()) {
            u = _Q.top ();
            _Q.pop ();
            
            if (_Flg[y] || _Flg[u.second]) {
                break ;
            }
            
            _Flg[u.second] = 1;
            
            for (auto v : _Mp[u.second]) {
                if (! _Flg[v.first]) {
                    _Dst[v.first] = min (u.first + v.second, _Dst[v.first]);
                    _Q.push (pair <int, int> {_Dst[v.first], v.first});
                }
            }
        }
    }
    
    void Main () {
        cin >> c >> n >> m >> d >> q;
        
        for (int i = 1; i <= m; ++ i) {
            cin >> w[i];
        }
        
        for (int i = 1; i <= n; ++ i) {
            cin >> k;
            
            while (k --) {
                cin >> a >> t;
                _Mp[a].push_back ( pair <int, int> {i + m, t});
                _Mp[i + m].push_back ( pair <int, int> {a, t});
            }
        }
        
//        exit (1);
//        
        while (q --) {
            cin >> x >> y;
            BFS ();
//            exit (1);
            cout << _Dst[y] + w[x] + w[y] << endl;
        }
        
        return ;
    }
}

signed main () {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    cin.tie (nullptr) -> ios :: sync_with_stdio (false);

    int T = 1;
//    cin >> T;

    while (T --) {
        luogu1038334_Ambrosia_guanzhuwo :: Main ();
    }

    return 0;
}

