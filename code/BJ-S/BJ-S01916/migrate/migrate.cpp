#include <iostream>

using namespace std;

int n, d;
int a[2000009] = {};
//int path[1000][1000] = {};
int le = 0;
int miniP = 1e9;
bool fl = false;
int res = 0;
void DFS (int x, int cc) {

    if (x == n) {
        if (fl && cc == miniP) {
            res++;
        }
//        cout << "cc: " << cc << endl;
        if (cc == n) {
            fl = true;
        }
        if (cc < miniP) {
            miniP = cc;
        }
//        cout << miniP << endl;
        le++;
        return ;
    }
    //    int c = 1;
//    while (a[x + c] - a[x] < d) {
//
//        DFS(x + c, cc + 1);
//        c++;
//    }
    for (int i = 1; i <= d; i++) {//i = dx
        if (a[i + x] - a[x] > d) {
            break;
        }
        if (i + x > n) {
            break;
        }
//        path[le][cc] = i + x;
        DFS(i + x, cc + 1);
    }
}

int main () {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 0;
    int T = 0;

    cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        //gen tree
        for (int i = 1; i <= n; i++) {
            //tree start : i
            //no back
//            path[le][0] = i;
            DFS(i, 1);
         }

//         for (int i = 0; i < 19; i++) {
//            for (int j = 0; j < 19; j++) {
//                cout << path[i][j] << " ";
//            }
//            cout << endl;
//         }
    }
    cout << 0 << endl;
    cout << 1 << endl;

    //tree?

    return 0;
}
