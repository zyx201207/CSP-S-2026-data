#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c_1,s_1,c_2,s_2;
    cin>>c_1>>s_1>>c_2>>s_2;
    string x=s_1.substr(0,2),y=s_2.substr(0,2);
    string a=s_1.substr(2,1),b=s_2.substr(2,1);
    if(c_1!=c_2)
    {
        cout<<"0000";
        return 0;
    }
    if(c_1==c_2)
    {
        cout<<1;
        if(x==y)
        {
            cout<<1;
            if(a=="A"&&b=="B" || a=="A"&&b=="C" || a=="D"&&b=="F" || a=="F"&&b=="D"
                || a=="B"&&b=="A" || a=="B"&&b=="C" || a=="C"&&b=="A" || a=="C"&&a=="B")
            {
                cout<<1;
                if(a=="A"&&b=="B" || a=="B"&&b=="C" || a=="D"&&b=="F" || a=="F"&&b=="D")
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    return 0;
}
