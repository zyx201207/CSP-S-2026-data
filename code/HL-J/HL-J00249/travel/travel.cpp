#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
        if(b[0]+b[1]==d[0]+d[1])
        {
            cout<<1;
            if(b[2]=='D'&&d[2]=='F')
            {
                cout<<11;
            }
            else if(b[2]=='F'&&d[2]=='D')
            {
                cout<<11;
            }
            else if(b[2]=='A'&&(d[2]=='B'||d[2]=='C'))
            {
                cout<<1;
                cout<<(d[2]=='B');
            }
            else if(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))
            {
                cout<<1;
                cout<<(d[2]=='A'||d[2]=='C');
            }
            else if(b[2]=='C'&&(d[2]=='A'||d[2]=='B'))
            {
                cout<<1;
                cout<<(d[2]=='B');
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

