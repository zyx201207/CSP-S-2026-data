#include<bits/stdc++.h>
using namespace std;
long long c1,c2,z1,z2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1 != c2)
    {
        cout<<"0000";
        return 0;
    }
    z1=(s1[0]-'0')*10+s1[1]-'0';
    z2=(s2[0]-'0')*10+s2[1]-'0';
    if(z1 != z2)
    {
        cout<<"1000";
        return 0;
    }
    if(s1[2] <= 'C'&&s2[2] >= 'D')
    {
        cout<<"1100";
        return 0;
    }
    if(abs(s1[2]-s2[2]) == 1)
    {
        cout<<"1111";
        return 0;
    }
    cout<<"1110";
    return 0;
}
