#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int a1 = (s1[0]-'0') * 10 + (s1[1]-'0'), a2 = (s2[0]-'0') * 10 + (s2[1]-'0');
    if (c1 != c2)
    {
        cout << "0000\n";
    }
    else if (a1 != a2)
    {
        cout << "1000\n";
    }
    else if ((abs(s1[2] - s2[2]) == 1 && max(s1[2], s2[2]) != 'D') || 
            (s1[2] == 'D' && s2[2] == 'F') || 
            (s1[2] == 'F' && s2[2] == 'D'))
    {
        cout << "1111\n";
    }
    else if ((s1[2] <= 'C' && s2[2] > 'C') || (s1[2] > 'C' && s2[2] <= 'C'))
    {
        cout << "1100\n";
    }
    else
    {
        cout << "1110\n";
    }
    return 0;
}