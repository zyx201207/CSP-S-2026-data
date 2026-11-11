#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }

    if(s1[0]==s2[0] && s1[1]==s2[1])
    {

        cout<<1;
    }
    else
    {
        cout<<0<<0<<0;
        return 0;
    }

    int v1,v2;
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C') v1=3;
    else v1=2;
    if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') v2=3;
    else v2=2;
    if(v1==v2)
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0;
        return 0;
    }

    if(v1==v2 && v2==3)
    {
        if(!(s1[2]=='A' && s2[2]=='C') && !(s1[2]=='C' && s2[2]=='A'))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    else
    {
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
