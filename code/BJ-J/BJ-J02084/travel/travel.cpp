#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    int cx,sx;
    string cy,sy;
    cin>>cx>>cy>>sx>>sy;
    int a,b,c,d;
    char x,y;
    a=cx;
    c=sx;
    b=(cy[0]-'0')*10+(cy[1]-'0');
    d=(sy[0]-'0')*10+(sy[1]-'0');
    x=cy[2];
    y=sy[2];
    if(a==c)
    {
        cout<<"1";
        if(b==d)
        {
            cout<<"1";
            if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))
            {
                cout<<"1";
                if(x=='A'&&y=='B')
                {
                    cout<<"1";
                }
                else if(x=='B'&&y=='A')
                {
                    cout<<"1";
                }
                else if(x=='B'&&y=='C')
                {
                    cout<<"1";
                }
                else if(x=='C'&&y=='A')
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else if((x=='D'||x=='E')&&(y=='D'||y=='E'))
            {
                cout<<"11";
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
    return 0;
}
