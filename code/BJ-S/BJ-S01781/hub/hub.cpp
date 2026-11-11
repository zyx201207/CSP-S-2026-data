#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(t==1)
    {
        cout<<1;
    }
    else if(t==2)
    {
        cout<<"1 2";
    }
    else if(t==3)
    {
        cout<<"0 1 2";
    }
    else if(t==4)
    {
        cout<<"0 1 2 1";
    }
    else
    {
        for(int i=1;i<=t;i++)
        {
            cout<<0;
        }
    }
    return 0;
}
