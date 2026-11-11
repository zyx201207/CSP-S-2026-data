
#include <iostream>

using namespace std;

struct Sr {

    int num;
    char c;
};

Sr a[200009] = {};

int main () {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    long long L = 0;
    long long R = 0;
    long long res = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].num >> a[i].c;
    }
//    cout << n << endl;

    L = 1;
    R = n;
//    cout << L << " ; " << R << endl;
    while (L < R) {
//        cout << "InWhile" << endl;
        if (a[L].c != a[R].c) {
            if (a[L].num > a[R].num) {
                res += a[R].num;
                a[L].num -= a[R].num;
                a[R].num = 0;
                R--;
            }
            else if (a[L].num < a[R].num) {
                res += a[L].num;
                a[R].num -= a[L].num;
                a[L].num = 0;
                L++;
            }
            else {
                res += a[R].num;
                a[L].num = 0;
                a[R].num = 0;
                L++;
                R--;
            }
        }
        else {
            //num != num
            if (a[L].num > a[R].num) {
                a[L].num -= a[R].num;
                a[R].num = 0;
                R--;
            }
            else if (a[L].num < a[R].num) {
                a[R].num -= a[L].num;
                a[L].num = 0;
                L++;
            }
            else {
                a[L].num = 0;
                a[R].num = 0;
                L++;
                R--;
            }
        }
    }

    cout << res << endl;

//    for (int i = 1; i <= n / 2; i++) {
//        if (a[i].c != a[n - i + 1].c) {
//            res += min(a[i].num, a[n - i + 1].num);
//        }
//    }      ERROR!!!!
    return 0;
}
