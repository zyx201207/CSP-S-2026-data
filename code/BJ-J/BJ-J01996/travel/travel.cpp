#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }
    int a = s1[0] - '0';
    a *= 10;
    a += s1[1] - '0';
    int b = s2[0] - '0';
    b *= 10;
    b += s2[1] - '0';
    if(a == b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }
    char x1 = s1[2];
    char x2 = s2[2];
    if(x1 == 'A' && (x2 == 'B' || x2 == 'C') || x2 == 'A' && (x1 == 'B' || x1 == 'C') || x1 == 'D' && x2 == 'F' || x2 == 'D' && x1 == 'F')
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        cout << 0;
        return 0;
    }
    int x = x1 - x2;
    if(abs(x) == 1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
//Trick||Treat!
