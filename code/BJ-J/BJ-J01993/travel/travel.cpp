#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,d1,d2;
    cin>>c1>>c2>>d1>>d2;
    bool a1=0,a2=0,a3=0,a4=0;
    if(c1==d1)
    {
        a1=1;
        if(c2[0]==d2[0]&&c2[1]==d2[1])
        {
            a2=1;
            if(c2[2]<='C'&&d2[2]<='C'||c2[2]>'C'&&d2[2]>'C')
            {
                a3=1;
                if(abs(c2[2]-d2[2])<=1)
                {
                  a4=1;
                }
            }
        }
    }
    cout<<a1<<a2<<a3<<a4;
}
