#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == y1) cout << '1';
    else cout << '0';
    string ans1, ans2;
    for (int i = 0; i <= 1; i++)
    {
        ans1+=y1[i];
        ans2+=y2[i];
    }
    if (ans1 == ans2) cout << '1';
    else cout << '0';
    string a = y1[2], b = y1[2];
    if (a == 'A' && b=='B') cout << '1';
    else if (a == 'A' && b=='C') cout << '1';
    else if (a == 'B' && b=='C') cout << '1';
    else if (a == 'B' && b=='A') cout << '1';
    else if (a == 'C' && b=='A') cout << '1';
    else if (a == 'C' && b=='B') cout << '1';
    else if (a == 'D' && b=='F') cout << '1';
    else if (a == 'F' && b=='D') cout << '1';
    else cout << '0';
    if (a == 'A' && b=='B') cout << '1';
    else if (a == 'B' && b=='A') cout << '1';
    else if (a == 'B' && b=='C') cout << '1';
    else if (a == 'C' && b=='B') cout << '1';
    else if (a == 'D' && b=='F') cout << '1';
    else if (a == 'F' && b=='D') cout << '1';
    else cout << '0';
    return 0;
}
