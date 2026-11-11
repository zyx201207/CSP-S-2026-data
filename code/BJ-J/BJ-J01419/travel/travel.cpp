#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
string ans="0000";
int side[128];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    side['A']=side['B']=side['C']=1;
    side['D']=side['F']=2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2)
    {
        ans[0]='1';
    }
    else
    {
        cout<<ans<<endl;
        return 0;
    }
    if (s1.substr(0,2)==s2.substr(0,2))
    {
        ans[1]='1';
    }
    else
    {
        cout<<ans<<endl;
        return 0;
    }
    if (side[s1[2]]==side[s2[2]])
    {
        ans[2]='1';
    }
    else
    {
        cout<<ans<<endl;
        return 0;
    }
    if (s1[2]=='A')
    {
        if (s2[2]=='B')
        {
            ans[3]='1';
        }
        else
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    else if (s1[2]=='B')
    {
        if (s2[2]=='A'||s2[2]=='C')
        {
            ans[3]='1';
        }
        else
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    else if (s1[2]=='C')
    {
        if (s2[2]=='B')
        {
            ans[3]='1';
        }
        else
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    else if (s1[2]=='D')
    {
        if (s2[2]=='F')
        {
            ans[3]='1';
        }
        else
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    else
    {
        if (s2[2]=='D')
        {
            ans[3]='1';
        }
        else
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}