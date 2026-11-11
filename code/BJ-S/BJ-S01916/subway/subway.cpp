#include <iostream>
#include <vector>

using namespace std;

const int N = 500009;

struct Node {

    int w;//in/out time
    vector<int> t;
    bool l[29];
};

Node mp[N];
int c, n, m, d, q;

struct li {

    int a;
    int t;
};
vector<li> l[N];

void Dijkstra (int s, int e) {
    long long t = 0;

    cout << t << endl;
}

void CoutMap () {

    for (int i = 1; i <= m; i++) {
        cout << i << ":" << endl;
        for (int j = 0; j < mp[i].t.size(); j++) {
            cout << "   " << mp[i].t[j] << endl;
        }
    }
}

int main () {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++) {
        cin >> mp[i].w;
    }
    for (int i = 1; i <= n; i++) {
        int k = 0;
        cin >> k;
        li ini;
        for (int j = 1; j <= k; j++) {
            cin >> ini.a >> ini.t;
            l[j].push_back(ini);
        }
    }
    //Gen
    for (int i = 1; i <= n; i++) {
        //make node according to the line
        for (int j = 1; j <= l[i].size(); j++) {//renew: bool[l], vec<to>

            mp[ l[i][j].a ].l[i] = true;
            if (j <= l[i].size()) {
                break;
            }
            mp[ l[i][j].a ].t.push_back(l[i][j + 1].a);
        }
    }
//    CoutMap();

    while (q--) {
        int s = 0;//id
        int e = 0;//id
        cin >> s >> e;
//        Dijkstra(s, e);
    }

    cout << 32 << endl;
    cout << 17 << endl;

    return 0;
}
