#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define fin freopen("travel.in","r",stdin);
#define fout freopen("travel.out","w",stdout);
using namespace std;
string a,b,c,d;
int main()
{
    fin
    fout
    cin >> a >> b >> c >> d;
    if(a==c)
    {
        if(b[0]==d[0] && b[1]==d[1])
        {
            char x=b[2],y=d[2];
            if(x<='C' && y<='C')
            {
                if(x=='B' || y=='B')
                    cout << "1111\n";
                else
                    cout << "1110\n";

            }
            else if(x>='D' && y>='D')
            {
                cout << "1111\n";
            }
            else
                cout << "1100\n";
        }
        else
            cout << "1000\n";
    }
    else
    {
        cout << "0000\n";
    }
    return 0;
}
