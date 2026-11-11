#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int a[10];

/// @brief
/// @return
int main()
{

    feropen("travel.in", "r", stdin);
    feropen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == "17" || c2 == "17" && c1 != "17" || c2 != "17")
    {
        a[0]++;
    }
    if (c1[0] == c2[0] || c1[1] == c2[1])
    {
        a[1]++;
    }
    if (a[1] == 1)
    {
        if (c1[3] - c2[3])
    }

    return 0;
}
