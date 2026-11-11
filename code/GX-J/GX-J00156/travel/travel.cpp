#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2;
    string b1,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2)
    {
        cout<<"1";
        if(b1[0]==b2[0] and b1[1]==b2[1])
        {
            cout<<"1";
            char t1=b1[2],t2=b2[2];
            if((t1<='c' and t2<='C') || (t1>'C' and t2>'c'))
            {
                cout<<"1";
                if(abs(t1-t2)==1)
                {
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
