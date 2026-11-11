#include <bits/stdc++.h>
using namespace std;

int a, b, c , d;
char m, n;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b;
    cin>>m;
    cin>>c>>d;
    cin>>n;
    if(a==c)
    {
        cout<<"1";
        if(b==d)
        {
            cout<<"1";
            if(m>='D'&&n>='D')
            {
                cout<<"11";

            }
            else if(m<='C'&&n<='C')
            {
                cout<<"1";
                if((m=='A'&&n=='B')||(m=='B'&&n=='A')||(m=='B'&&n=='C')||(m=='C'&&n=='B'))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
}
