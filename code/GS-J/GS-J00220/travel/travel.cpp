#include <bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
char cc[3];
bool t,t1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for (int i = 0;i<c1.size();i++)
    {
        if (c1[i]!=c2[i])
        {
            cout<<"0000";
            return 0;
        }
    }
    for (int i =0;i<s1.size()-1;i++)
    {
        if (s1[i]!=s2[i])
        {
            cout<<"1000";
            return 0;
        }
    }
    cc[0]=s1[2];
    cc[1]=s2[2];
    if (cc[0]=='F'||cc[1]=='D')
    {
        t=0;
    }
    else
    {
        t=1;
    }
    if (cc[1]=='F'||cc[0]=='D')
    {
        t1=0;
    }
    else
    {
        t1=1;
    }
    if (t!=t1)
    {
        cout<<"1100";
        return 0;
    }
    if (t==0)
    {
        cout<<"1111";
        return 0;
    }
    else if(cc[0]=='A'&&cc[1]=='C' || cc[0]=='C'&&cc[1]=='A')
    {
        cout<<"1110";
    }
    else
    {
        cout<<"1111";
    }
    return 0;
}
