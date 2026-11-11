#include<bits/stdc++.h>
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool f1=0,f2=0,f3=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        f1=1;
    }
    else cout<<"0";


    if(f1 and s1[0]==s2[0] and s1[1]==s2[1])
    {
        cout<<"1";
        f2=1;
    }
    else cout<<"0";


    if(s1[2]<='F' and s1[2]>='D' and s2[2]<='C' and s2[2]>='A')
    {
        cout<<"0";
    }
    else
    {
        if(s2[2]<='F' and s2[2]>='D' and s1[2]<='C' and s1[2]>='A')
        {
            cout<<"0";
        }
        else
        {
            if(f2)
            {
                cout<<"1";
                f3=1;
            }
            else cout<<"0";
        }
    }


    int a=s1[2]-'0',b=s2[2]-'0';
    if(abs(a-b)==1)
    {
        if((a==68 and b==67)or(a==67 or b==68))
        {
            cout<<"0";
        }
        else
        {
            if(f3)cout<<"1";
            else cout<<"0";
        }
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
