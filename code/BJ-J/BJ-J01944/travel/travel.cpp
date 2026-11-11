#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",std);
    freopen("travel.out","w",std);
    string a1,a2,b1,b2;
    cin >> a1 >>a2 >> b1 >> b2;
    int a = (a1[0]-'0')*10+a1[1]-'0';
    int b = (b1[0]-'0')*10+b1[1]-'0';
    int ap = (a2[0]-'0')*10+a2[1]-'0';
    int bp = (b2[0]-'0')*10+b2[1]-'0';
    int az = a2[2]-'A';
    int bz = b2[2]-'A';
    if(a==b)
    {
        if(ap==bp)
        {
            if((az<3&&bz<3)||(az>2&&bz>2))
            {
                if((az+1==bz||bz+1==az))
                {
                    cout << 1111;
                }
                else
                {
                    cout << 1110;
                }
            }
            else
            {
                cout << 1100;
            }
        }
        else
        {
            cout << 1000;
        }
    }
    else
    {
        cout << 0000;
    }
}
