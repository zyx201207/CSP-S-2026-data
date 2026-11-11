#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "0";
        return 0;
    }

    int cnt_c_1 = 0;
    char c_1 = '0';

    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        if (i == 1 && c_1 != c) {
            c_1 = c;
        }

        if (i > 1 && c != c_1)
        {
            ++cnt_c_1;
        }

        if (n == 2) {
            if (cnt_c_1 > 0) {
                cout << "1";
                return 0;
            }

            else {
                cout << "0";
                return 0;
            }
        }
    }



    return 0;
}
