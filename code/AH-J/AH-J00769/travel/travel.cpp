#include <bits/stdc++.h>
using namespace ctd;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d,e,f,g,h;
    cin >> a >> b >> c >> d;
    if (a == c)
    {
        cout << "1";
        for (int i = 0;i <= 3;i++)
        {
            if (i <= 2)
                e[i] = b[i];
            else
                f[i - 2] = d[i - 2];
        }
        if (e == f)
        {
            cout << "1";
            g = b[2];
            h = d[2];
            if((g == "A"&&h == "B")||(g == "A"&&h == "C")||(g == "B"&&h == "A")||(g == "B"&&h == "C")||(g == "C"&&h == "A")||(g == "C"&&h == "B")||(g == "D"&&h == "F")||(g == "F"&&h == "D"))
            {
                cout << "1";
                if ((g == "A"&&h == "B")||(g == "B"&&h == "A")||(g == "B"&&h == "C")||(g == "C"&&h == "B")||(g == "D"&&h == "F")||(g == "F"&&h == "D"))
                    cout << "1";
                else
                    cout << "0";
            }
            else
                cout << "00";
        }
        else
            cout << "000";
    }
    else
        cout << "0000";
    return 0;
}
