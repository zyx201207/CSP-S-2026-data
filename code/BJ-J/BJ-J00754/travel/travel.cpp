#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool b1=0,b2=0,b3=0,b4=0;
bool f=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if(a[0]==c[0]&&a[1]==c[1])
    {
        b1=1;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&b1)
    {
        b2=1;
    }
    if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')
    {
        if(b1&&b2) b3=1;
    }
    if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'&&b1&&b2&&b3)
    {
        if(abs(int(b[2]-d[2]))==1)
        {
            b4=1;
        }
    }
    else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'&&b1&&b2&&b3)
    {
        b4=1;
    }
    cout << b1 << b2 << b3 << b4 << endl;
    return 0;
}
