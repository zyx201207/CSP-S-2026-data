#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,y;
    char a[5],b[5];
    cin>>x;
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    cin>>y;
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    if(x==y)
    {
        cout<<"1";
        if(a[0]==b[0]&&a[1]==b[1])
        {
            cout<<"1";
            if((a[2]=='D'&&b[2]=='E')||(a[2]=='E'&&b[2]=='D')||((a[2]=='C'||a[2]=='B'||a[2]=='A')&&(b[2]=='C'||b[2]=='B'||b[2]=='A')))
            {
                cout<<"1";
                if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A')||(a[2]=='C'&&b[2]=='B')||(a[2]=='B'&&b[2]=='C')||(a[2]=='D'&&b[2]=='E')||(a[2]=='E'&&b[2]=='D'))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
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
