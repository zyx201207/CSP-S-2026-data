#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t,r,u;
    cin>>s>>t>>r>>u;
    if(s==r)
    {
        cout<<1;
        string p="";
        p+=t[0];
        p+=t[1];
        string k="";
        k+=u[0];
        k+=u[1];
        if(p==k)
        {
            cout<<1;
            if((t[2]=='F'&&u[2]=='D')||(t[2]=='D'&&u[2]=='F')||(t[2]=='A'&&u[2]=='B')||(t[2]=='B'&&u[2]=='A')||(t[2]=='A'&&u[2]=='C')||(t[2]=='C'&&u[2]=='A')||(t[2]=='B'&&u[2]=='C')||(t[2]=='C'&&u[2]=='B'))
            {
                cout<<1;
                if((t[2]=='F'&&u[2]=='D')||(t[2]=='D'&&u[2]=='F')||(t[2]=='A'&&u[2]=='B')||(t[2]=='B'&&u[2]=='A')||(t[2]=='B'&&u[2]=='C')||(t[2]=='C'&&u[2]=='B'))
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
                cout<<0<<0;
            }
        }
        else
        {
            cout<<0<<0<<0;
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
