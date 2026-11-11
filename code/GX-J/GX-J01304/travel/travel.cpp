#include <bits/stdc++.h>
using namespace std;
int r1,x1,r2,x2;
string r,x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r>>x1>>x;
    r2 = r[0]-'0';
    r2 = r2*10+r[1]-'0';
    x2 = x[0] - '0';
    x2 = x2 *10+x[1]-'0';
    int r3 = r[2]-'A'+1;
    int x3 = x[2]-'A'+1;
    if(r1 == x1)
    {
        cout<<1;
        if(r2 == x2)
        {
            cout<< 1;
            if((r3<=3 && x3 <= 3) || (r3>=4&&x3>=4))
            {
                cout<<1;
                if(max(r3-x3,x3-r3) == 1)
                {
                    cout<<1;
                }
                else{
                    cout<<0;
                }

            }
            else{
                cout<<0;
                cout<<0;
            }
        }
        else{
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }

    return 0;
}
