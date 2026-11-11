#include <bits/stdc++.h>
using namespace std;

int a[3];string b[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a[1]>>b[1]>>a[2]>>b[2];
    if(a[1]==a[2])
    {
        cout<<1;
        if((b[1][0]-'0')*10+b[1][1]==(b[2][0]-'0')*10+b[2][1])
        {
            cout<<1;
            if(b[1][2]-'A'<=3&&b[2][2]-'A'<=3||b[1][2]-'A'>3&&b[2][2]-'A'>3)
            {
                cout<<1;
                if(b[1][2]+1==b[2][2]||b[2][2]+1==b[1][2])
                {
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
