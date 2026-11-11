#include <iostream>

using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string rs, xs;
    int rc, xc, ck1 = 0, ck2 = 0, ck3 = 0, ck4 = 0;
    cin >> rc >> rs >> xc >> xs;            //rc, xc分别表示小 R 的车票上的车厢号以及小 X 的车票上的车厢号
    if (rc == xc) ck1 == 1;
    else {
        cout << ck1 << ck2 << ck3 << ck4 << endl;
        return 0;
    }
    for (int j = 0; j < 2; j++) {
        if (rs[j] - '0' == xs[j] - '0') ck2 = 1;
        else {
            cout << 1000 << endl;
            return 0;
        }
    }
    if ((rs[2] <= 'C' && xs[2] <= 'C') || (rs[2] > 'C' && xs[2] > 'C')) ck3 = 1;
    else {
        cout << 1100 << endl;
        return 0;
    }
    if (rs[2] + '1' == xs[2] || rs[2] - '1' == xs[2]) ck4 = 1;
    else {
        cout << 1110 << endl;
        return 0;
    }
    cout << 1111 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
