#include <bit/stdc++.h>
using namespace std;

int c, m, n, d, q

struct Station {
    int w;
    vector<pair<int, int>> tn;
};

Station sta[500005];
vector<pair<int, int>> subwayMap;

int solve(int begin, int end) {
    int endlines = sta[end].tn.size();
    for (int i = 0; i < endlines; i++) {
        
    }
    for (int i = 0; i)
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> sta[i].w;
    for (int i = 1; i<= n; i++) {
        int lastSta = 0;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a;
            cin >> t;
            sta[a].tn.push_back(make_pair(a, t));
            if (lastSta != 0) subwayMap.push_back(make_pair(lastSta, a));
            lastSta = a;
        }
    }
    for (int i = 1; i <= q; i++) {
        int begin, end;
        cin >> begin >> end;

    }
    return 0;
}
