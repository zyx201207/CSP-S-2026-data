#include<iostream>
#include<string>
using namespace std;

string r,x;
char r1,r2,r3;
char x1,x2,x3;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>r>>r1>>r2>>r3;
    cin>>x>>x1>>x2>>x3;

    if(r!=x)
        cout<<"0000";
    else
    {
        if(r1!=x1 || r2!=x2)
            cout<<"1000";
        else
        {
            if(r3<='C' && x3>='D'
            || r3>='D' && x3<='C')
                cout<<"1100";
            else
            {
                if(r3=='A' && x3=='C'
                || r3=='C' && x3=='A')
                    cout<<"1110";
                else
                    cout<<"1111";
            }
        }
    }

    return 0;
}
