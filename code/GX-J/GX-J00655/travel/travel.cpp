#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a1, b1;
    string a2, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    bool f1 = (a1 == b1);
    bool f2 = ((a2[0] == b2[0]) && (a2[1] == b2[1]));
    f2 = f1 && f2;
    bool f3 = ((a2[2] <= 'C') == (b2[2] <= 'C'));
    f3 = f2 && f3;
    bool f4 = (abs(a2[2] - b2[2]) == 1);
    f4 = f3 && f4;
    cout << f1 << f2 << f3 << f4;
    return 0;
}
//we don't care what they say
//we will be here all day
//it not till it's over
//we will stand, we will fight
//it not till it's over
