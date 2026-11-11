#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;

    bool pd=false;
    if(a==b)
    {
        cout<<"1";
        pd=true;
    }
    if(pd==false)
    {
        cout<<"0";
    }


    pd=false;
    if(a==b && c[0]==d[0] && c[1]==d[1])
    {
        cout<<"1";
        pd=true;
    }
    if(pd==false)
    {
        cout<<"0";
    }

    pd=false;
    if(a==b && c[0]==d[0] && c[1]==d[1])
    {
        if(c[2]=='C'&&d[2]=='D')
        {
            cout<<"0";
            pd=true;
        }
        if(c[2]=='D'&&d[2]=='C')
        {
            cout<<"0";
            pd=true;
        }
        if(pd==false)
        {
            cout<<"1";
            pd=true;
        }
    }
    if(pd==false)
    {
        cout<<"0";
    }

    pd=false;
    if((abs(c[2]-d[2])==1)&&a==b && c[0]==d[0] && c[1]==d[1])
    {
        if(c[2]=='C'&&d[2]=='D')
        {
            cout<<"0";
            pd=true;
        }
        if(c[2]=='D'&&d[2]=='C')
        {
            cout<<"0";
            pd=true;
        }
        if(pd==false)
        {
            cout<<"1";
            pd=true;
        }
    }
    if(c[2]=='D'&&d[2]=='F')
    {
        cout<<"1";
        pd=true;
    }
    if(c[2]=='F'&&d[2]=='D')
    {
        cout<<"1";
        pd=true;
    }
    if(pd==false)
    {
        cout<<"0";
    }
    return 0;
}
