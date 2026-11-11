#include <bits/stdc++.h>
using namespace std;
bool left(char a)
{
    return a == 'A' || a == 'B' || a == 'C';
}
bool check1(char a, char b)
{
    return left(a) == left(b);
}
bool check2(char a, char b)
{
    char s = min(a, b);
    char t = max(a, b);
    if(s == 'A' && t == 'B')
        return true;
    if(s == 'B' && t == 'C')
        return true;
    if(s == 'D' && t == 'F')
        return true;
    return false;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a1, a2, b1, b2;
    char a3, b3;
    scanf("%d %d%c %d %d%c", &a1, &a2, &a3, &b1, &b2, &b3);
    if(a1 == b1)
    {
        cout << 1;
        if(a2 == b2)
        {
            cout << 1;
            if(check1(a3, b3))
            {
                cout << 1;
                cout << check2(a3, b3);
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}