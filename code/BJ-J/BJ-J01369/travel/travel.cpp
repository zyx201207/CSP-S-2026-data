#include <iostream>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1 == b1)
    {
        cout << "1";
        string s1 = "";
        string s2 = "";
        s1 += a2[0];
        s2 += b2[0];
        s1 += a2[1];
        s2 += b2[1];
        if(s1 == s2)
        {
            cout << "1";
            char a = a2[2];
            char b = b2[2];
            if(a <= 'C' && b <= 'C' || a>= 'D' && b >='D')
            {
                cout << "1";
                if(int(a) - int(b) == 1 || int(a) - int(b) == -1)
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
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