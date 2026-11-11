#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    long long c1 , c2
    string s1 , s2;
    string p1 = s1.substr(0,2);
    string p2 = s2.substr(0,2);
    char z1 = s1.substr(2,1);
    char z2 = s2.substr(2,1);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(p1 == p2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if((z1 <= 'C' && z2 <= 'C') || (z1 >= 'D' && z2 >= 'D'))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(z1 <= 'C' && z2 <= 'C' && (z1 + 1 == z2 || z1 - 1 == z2)
    {
        cout << 1;
    }
    else if(z1 >= 'D' && z2 >= 'D' && (z1 + 2 == z2 || z1 - 2 == z2)
    {
        cout << 0;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
