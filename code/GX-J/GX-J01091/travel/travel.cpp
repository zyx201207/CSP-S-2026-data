#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,s,l;
    cin>>a>>s>>b>>l;
    if(a==b)
    {
        cout<<1;
        if(s[0]==l[0]&&s[1]==l[1])
        {
            cout<<1;
            if(s[2]<'D'&&l[2]<'D')
            {
                cout<<1;
                if(s[2]+1==l[2]||l[2]+1==s[2])
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                if(s[2]>'C'&&l[2]>'C')
                {
                    cout<<1<<1;
                }
                else
                {
                    cout<<0<<0;
                }
            }
        }
        else
        {
            cout<<0<<0<<0;
        }
    }
    else
    {
        cout<<0<<0<<0<<0;
    }
    return 0;
}
