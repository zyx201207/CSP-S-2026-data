#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string s;
    if(c1==c2)
    {
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            if(s1[2]<='C' && s2[2]<='C')
            {
                if(s1[2]==s2[2]+1 || s1[2]==s2[2]-1) s="1111";
                else s="1110";
            }
            else if(s1[2]>='D' && s2[2]>='D') s="1111";
            else s="1100";
        }
        else s="1000";
    }
    else s="0000";
    cout<<s;
    return 0;
}
