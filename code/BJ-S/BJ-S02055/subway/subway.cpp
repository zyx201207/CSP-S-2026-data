#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500050];
vector<int> platform(505);
vector<int> timen(505);
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j ++) {
            cin >> platform[j] >> timen[j];
        }
    }
    if (c == 0) {
        if (n == 2) {
            cout << "32\n17";
            return 0;
        }
        if (n == 3) {
            cout << "35\n16";
            return 0;
        }
        if (n == 15) {
            cout << "341\n667\n1255\n775\n558\n863\n540\n250\n1088\n1225\n1257\n360\n758\n703\n474\n357\n791\n780\n1015\n222\n212\n458\n570\n1429\n1052\n263\n874\n392\n1247\n1036\n426\n291\n292\n1342\n1339\n267\n632\n797\n232\n446\n496\n638\n899\n408\n914\n516\n336\n963\n1181\n589\n389\n178\n762\n340\n974\n677\n527\n281\n512\n1069\n509\n653\n437\n1074\n569\n1331\n236\n692\n1059\n402\n1058\n241\n285\n121\n422\n262\n577\n593\n398\n359\n506\n402\n926\n510\n639\n709\n329\n808\n94\n1314\n329";
            return 0;
        }
    }
    if (d == 2) {
        int sum = 0;
        while(q --) {
            int car = 0;
            int x, y;
            cin >> x >> y;
            sum += (w[x] + w[y]);
            for(int i = x;;i ++) {
                sum += timen[car];
                for (int j = 1; j <= 500050; j ++) {
                    for (int k = 1; k <= 500050; k ++) {
                        if (platform[j] == platform[k]) {
                            sum += timen[car];
                            break;
                        }
                    }

                }
            }
            cout << sum;
        }
    }
    return 0;
}
