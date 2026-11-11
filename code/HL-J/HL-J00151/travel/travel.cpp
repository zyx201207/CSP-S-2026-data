#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,s,b,t;
    cin>>a>>s>>b>>t;
    if(a==b)
    {
        cout<<1;
        if(s.substr(0,2)==t.substr(0,2))
        {
            cout<<1;
            if(s[2]>'C'&&t[2]>'C')
            {
                cout<<11;
            }
            else if(s[2]<'D'&&t[2]<'D')
            {
                cout<<1;
                if(s[2]<'C'&&t[2]<'C')
                    cout<<1;
                else if(s[2]>'A'&&t[2]>'A')
                    cout<<1;
                else cout<<0;
            }
            else
            {
                cout<<00;
            }
        }
        else
        {
            cout<<000;
        }
    }
    else
    {
        cout<<0000;
    }
    return 0;
}
