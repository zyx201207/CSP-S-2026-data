#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a1,a2,b1,b2,b3,c1,c2,d1,d2,d3;
    cin>>a1>>a2>>b1>>b2>>b3>>c1>>c2>>d1>>d2>>d3;
    if(a1==c1&&a2==c2)
    {
        cout<<1;
        if(b1==d1&&b2==d2)
        {
            cout<<1;
            if(((b3=='A'||b3=='B'||b3=='C')&&(d3=='A'||d3=='B'||d3=='C'))||((b3=='D'||b3=='F')&&(d3=='D'||d3=='F')))
            {
                cout<<1;
                int a=b3,b=d3;
                if(abs(a-b)==1)
                {
                    cout<<1;
                    return 0;
                }
                else if(abs(a-b)==2&&((b3=='D'&&d3=='F')||(b3=='F'&&d3=='D')))
                {
                    cout<<1;
                    return 0;
                }
                else
                {
                    cout<<0;
                    return 0;
                }
            }
            else
            {
                cout<<"00";
                return 0;
            }

        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    return 0;
}
