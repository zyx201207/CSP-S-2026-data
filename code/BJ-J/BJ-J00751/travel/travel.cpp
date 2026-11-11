#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//int ;
//const int N = ;

//int ;
string c1, s1, c2, s2;

void solve()
{
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << '1';
        if (s1.substr(0, 2) == s2.substr(0, 2))
        {
            cout << '1';
            if (s1[2] < 'D' && s2[2] < 'D' || s1[2] > 'C' && s2[2] > 'C')
            {
                cout << '1';
                if (abs(s1[2] - s2[2]) < 2)
                    cout << '1';
                else cout << '0';
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//O(1), O(1), 100pts
