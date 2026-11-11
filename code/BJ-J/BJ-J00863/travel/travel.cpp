#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool check1(int a, int b)
{
    if(a <= 3 && b <= 3 || a >= 4 && b >= 4) return 1;
    return 0;
}
bool check2(int a, int b)
{
    if(abs(a-b) == 1 && !(a == 3 && b == 4) && !(a == 4 && b == 3)) return 1;
    return 0;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << 1;
        if(s1.substr(0, 2) == s2.substr(0, 2))
        {
            cout << 1;
            int a = s1[2] - 'A' + 1, b = s2[2] - 'A' + 1;
            if(check1(a, b))
            {
                cout << 1;
                if(check2(a, b)) cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}