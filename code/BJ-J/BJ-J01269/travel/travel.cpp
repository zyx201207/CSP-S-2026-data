#include<bits/stdc++.h>
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c3;
    char a,b,c,d,e,f;
    cin>>c1>>a>>b>>c>>c3>>d>>e>>f;
    if(c1==c3)
    {
        cout<<"1";
        if(a==d && b==e)
        {
            cout<<"1";
            if((c=='D'|| c=='F') && (f=='D' || f=='F') || (c=='A'|| c=='B' || c=='C') && (f=='A' || f=='B' || f=='C'))
    {
        cout<<"1";
        if(abs(int(c)-int(f))==1)
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    else
    {
        cout<<"00";
    }
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