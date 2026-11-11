#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c && a != "01" && a != "16")
    {
        if (b / 10 == d / 10)
        {
            if ((b % 10 == "D" && d % 10 == "E") || (b % 10 == "E" && d % 10 == "D"));
            {
                cout << "1111";
            }
            else if (b % 10 <= 'C' && d % 10 <= 'C')
            {
                if ((b % 10 <= 'B' && d % 10 <= 'B') || (b % 10 >= 'B' && d % 10 >= 'B'))
                {
                    cout << "1111";
                }
                else
                {
                    cout << "1110";
                }
            }
            else
            {
                cout << "1100";
            }
        }
        else
        {
            cout << "1000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
