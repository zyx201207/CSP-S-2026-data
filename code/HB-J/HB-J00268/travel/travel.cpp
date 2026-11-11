#include <bits/stdc++.h>

using namespace std;

string str;
int posA, posB, sumA, sumB;
bool nxt, side;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    getline(cin, str);

    nxt = false;

    posA = int(str[3] - '0') * 10 + int(str[4] - '0');

    posB = int(str[10] - '0') * 10 + int(str[11] - '0');

    sumA = int(str[0] - '0') * 10 + int(str[1] - '0');

    sumB = int(str[7] - '0') * 10 + int(str[8] - '0');

    if((str[5] == 'D' && str[12] == 'F') || (str[5] == 'F' && str[12] == 'D'))
    {
        nxt = true;
        side = true;
    }

    if(str[5] >= 'A' && str[5] <= 'C' && str[12] >= 'A' && str[12] <= 'C')
    {
        side = true;
        if(abs(int(str[5] - str[12])) == 1)
        {
            nxt = true;
        }
    }

    bool a = bool(sumA == sumB);
    bool b = bool(posA == posB) & a;
    bool c = side & b;
    bool d = nxt & c;

    cout << a << b << c << d;

    return 0;
}
