#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1!=c2) cout<<"0000";
    else
    {
        if (s1.substr(0,2)!=s2.substr(0,2)) cout<<"1000";
        else
        {
            if (((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>'D'))==0) cout<<"1100";
            else
            {
                if (abs(s1[2]-s2[2])!=1) cout<<"1110";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
