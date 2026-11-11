#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        if(b[0]!=d[0] || b[1]!=d[1])
        {
            cout<<"1000";
            return 0;
        }
        else
        {

                if(b[2]=='A'&&b[2]=='C'||b[2]=='C'&&b[2]=='A')
                {
                    cout<<"1110";
                    return 0;
                }
                else
                {
                    cout<<"1111";
                }
            }
        }

    return 0;
}
