#include <bits/stdc++.h>
using namespace std;
int a, b ;
string str1,str2,str3,str4 ;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> str1 >> str2>> str3 >> str4 ;
    a = str1[1] - '0' ;
    a += (str1[0] - '0') * 10 ;
    b = str3[1] - '0' ;
    b += (str3[0] - '0') * 10 ;
    if ( a != b )
    {
        cout << 0 << 0 << 0 << 0 ;
    }
    else
    {
        cout << 1 ;
        a = str2[1] - '0' ;
        a += (str2[0] - '0') * 10 ;
        b = str4[1] - '0' ;
        b += (str4[0] - '0') * 10 ;
        if ( a != b )
        {
            cout << 0 << 0 << 0 ;
        }
        else
        {
            cout << 1 ;
            if ((str2[2] == 'D' || str2[2] == 'F') && (str4[2] == 'D' || str4[2] == 'F')) {
                cout << 1 << 1 ;
                return 0 ;
            }
            if ((str2[2] == 'A' || str2[2] == 'B' || str2[2] == 'C') && (str4[2] == 'A' || str4[2] == 'B' || str4[2] == 'C'))
            {
                cout << 1 ;
                if ( (str2[2] == 'A' && str4[2] == 'B') || (str2[2] == 'B' &&  str4[2] == 'A') || (str2[2] == 'B' && str4[2] == 'C') || (str2[2] == 'C' &&  str4[2] == 'B'))
                    cout << 1 ;
                else
                    cout << 0 ;
            }
            else
                cout << 0 << 0 ;
        }
    }
    return 0;
}
