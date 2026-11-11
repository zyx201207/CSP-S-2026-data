#include <bits/stdc++.h>
using namespace std;

//Remember long long;
//freopen() 召唤成功

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    char x, a_d, b_d;
    int a_c = 0, a_s = 0, b_c = 0, b_s = 0;
    cin >> x; a_c += (x - 48) * 10;
    cin >> x; a_c += (x - 48);

    cin >> x; a_s += (x - 48) * 10;
    cin >> x; a_s += (x - 48);
    cin >> a_d;

    cin >> x; b_c += (x - 48) * 10;
    cin >> x; b_c += (x - 48);

    cin >> x; b_s += (x - 48) * 10;
    cin >> x; b_s += (x - 48);
    cin >> b_d;

//  cout << a_c << ' ' << a_s << ' ' << a_d << '\n' << b_c << ' ' << b_s << ' ' << b_d;
    bool ans1 = (a_c == b_c);
    bool ans2 = (a_s == b_s && ans1);
    bool ans3 = (((ans1 && ans2) && (((a_d == 'A' ||  a_d == 'B' || a_d == 'C') && (b_d == 'A' ||  b_d == 'B' || b_d == 'c')) || ( (a_d == 'D' || a_d == 'F') && (b_d == 'D' || b_d == 'F')))));
    bool ans4 = (((ans1 && ans2) && ans3) && ((a_d == 'A' && b_d == 'B') || (a_d == 'B' && b_d == 'A') || (a_d == 'B' && b_d == 'C') || (a_d == 'C' && b_d == 'B') || (a_d == 'D' && b_d == 'F') || (a_d == 'F' && b_d == 'D')));
    cout << ans1 << ans2 << ans3 << ans4;

    return 0;
}
/*
Good time
Woke up on the right side of the bed,
What wrong with this spirit song inside my head?
Forget words *1
Cause it always a good time
...
...
We dont even have to try, It always a good time
*/
