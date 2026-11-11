
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {

    int k = 0;
    int num = 0;
    int a[31] = {};
};
Node t[200009] = {};

int len = 0;
void Cut (int x) {
//    cout << x << endl;
    t[len].k = x;
    int cc = 30;
    long long k = 0;
    while (x > 0) {
        k = (1 << cc);
//        cout << cc << "--->" << k << endl;
        if (x >= k) {
//                cout << "?" << endl;
            x -= k;
            t[len].a[cc]++;
            t[len].num++;
        }
        cc--;
    }

//    if (t[len].k == 512) {
//        cout << (1 << 9) << endl;
//        for (int i = 30; i >= 0; i--) {
//            cout << t[len].a[i] << " ";
//        }
//        cout << endl;
//    }
    len++;
}

bool cmp (Node x, Node y) {
//    cout << x.k << ", " << y.k  << endl;
//    for (int i = x.num; i >= 0; i--) {
//        if (x.a[i] > y.a[i]) {
//           return x.a[i] > y.a[i];
//        }
//        if (x.a[i] < y.a[i]) {
//           return x.a[i] < y.a[i];
//        }
//    }
//    return x.num > y.num;

    if (x.num == y.num) {
        for (int i = x.num; i >= 0; i--) {
            if (x.a[i] > y.a[i]) {
                return x.a[i] > y.a[i];
            }
            if (x.a[i] < y.a[i]) {
                return x.a[i] < y.a[i];
            }
        }
        return x.num > y.num;
    }
    return x.num > y.num;
}

int main () {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //getline(cin, ?)

    int n = 0;
    int m = 0;

    cin >> n >> m;
//    cout << n << m << endl;
    for (int i = 0; i < n; i++) {
        int k = 0;
        cin >> k;
        Cut(k);
    }

//    cout << "------------------1-------" << endl;
    sort(t, t + n + 1, cmp);
//    for (int i = 0; i < len; i++) {
//        cout << t[i].k << " ";
//    }
//    cout << endl;
//    cout << "---------------------2------------" << endl;
    long long res = 0;
    res = t[0].k;
//    cout << res << endl;
    for (int i = 1; i < m; i++) {
//        cout << t[i].k << endl;
        res = res & t[i].k;
    }
    cout << res << endl;
    return 0;
}
