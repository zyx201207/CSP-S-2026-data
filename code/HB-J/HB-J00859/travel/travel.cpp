#include<bits/stdc++.h>
using namespace std;
int c1,c2,m,n;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    if(s1[1]!=s2[1] && s1[2]!=s2[2])
    {
        cout<<"1000";
        return 0;
    }
    m=s1[3];
    n=s2[3];
    if(m<=67 && n>67 || m>67 && n<=67)
    {
        cout<<"1100";
        return 0;
    }
    if(m+1==n || n+1==m)
    {
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
