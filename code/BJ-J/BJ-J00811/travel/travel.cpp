#include <bits/stdc++.h>
using namespace std;
bool chk(char a, char b)
{
    if(a <= 'C'&& b <= 'C') return true;
    if(a >= 'D' && b >= 'D') return true;
    return false;
}
bool check(char a, char b)
{
    if((a == 'A' && b == 'B') || (a == 'B' && b == 'A')) return true;
    if((a == 'B' && b == 'C') || (a == 'C' && b == 'B')) return true;
    if((a == 'D' && b == 'F') || (a == 'F' && b == 'D')) return true;
    return true;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
    {
        printf("0000");
        return 0;
    }
    cout << 1;
    if(s1[0] != s2[0] || s1[1] != s2[1])
    {
        printf("000");
        return 0;
    }
    cout << 1;
    char seatr = s1[2];
    char seatx = s2[2];
    if(!chk(seatr, seatx))
    {
        printf("00");
        return 0;
    }
    cout << 1;
    if(check(seatr, seatx))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
