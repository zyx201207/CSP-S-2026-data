#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1!=c2)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    int k1=(s1[0]-48)*10+s1[1]-48;
    int k2=(s2[0]-48)*10+s2[1]-48;
    if (k1!=k2)
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))
        cout << 1;
    else
    {
        cout << "00";
        return 0;
    }
    if (abs(s1[2]-s2[2]) == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}