#include<bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int a , b , c , d;
    char b1 , d1;
    cin >> a >> b >> b1 >> c >> d >> d1;
    if(a == c)
    {
        cout << 1;
        if(b == d)
        {
            cout << 1;
            if(((b1 == 'A' || b1 == 'B' || b1 == 'C') && (d1 == 'A' || d1 == 'B' || d1 == 'C')) || ((b1 == 'D'  || b1 == 'E') && (d1 == 'D' || d1== 'E')))
            {
                 cout << 1;
                 if(abs(d1 - b1) == 1)
                 {
                     if(b1 == 'C' && d1 == 'D' || b1 == 'D' && d1 == 'C')
                     {
                         cout << 0;
                     }
                     cout << 1
                 }
            }   
            else
            {
                   cout << 00;
            }
        }
        else
        {
             cout << 000;
        }
    }
    else
    {
        cout << 0000;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}