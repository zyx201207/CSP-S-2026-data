#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int flag1 = 0,flag2 = 0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        if(s1[1]==s2[1]&&s2[0]==s2[0])
        {
            cout<<1;
            int flag = 1;
            if(s1[2]=='C'&&s2[2]=='D') flag = 0;
            if(s1[2]=='D'&&s2[2]=='C') flag = 0;
            if(flag==1)
            {
                cout<<1;
                if(abs(s1[2]-s2[2])==1)cout<<1;
            }
            else cout<<"00";

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
