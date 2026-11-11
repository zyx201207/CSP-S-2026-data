#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b)
    {
        cout<<"1";
        if(c[0]==d[0] && c[1]==d[1])
        {
            cout<<"1";
            if(c[2]>='D' && d[2]>='D')cout<<"11";
            else
            {
                if(c[2]<='C' && d[2]<='C')
                {
                    if(abs(c[2]-d[2])>1)cout<<"10";
                    else cout<<"11";
                }
                else cout<<"00";
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 1;
}
