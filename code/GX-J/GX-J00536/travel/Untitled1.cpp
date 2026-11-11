#include <iostream>
using namespace std;
int main()
{
    fropen("travel.in","r",stdin);
    fropen("travel.out","w",stdout);
    chin a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }
    int e, f;
    e = b;
    f = d;
    if (e == f)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
