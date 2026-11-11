#include<bits/stdc++.h>
using namespace std;
int n,t;
string q,p,a,b;
char x,y;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>q>>a>>p>>b;
    if(q!=p)
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    cout<<1;

    int x,y;

    if(a[0]==b[0]&&a[1]==b[1])
    {

        cout<<1;
        if((a[2]=='F'||a[2]=='D') && (b[2]=='F'||b[2]=='D'))
        {
            cout<<11;
        }
        else if((a[2]=='A'||a[2]=='B'||a[2]=='C') && (b[2]=='A'||b[2]=='B'||b[2]=='C'))
        {
            cout<<1;
            if((a[2]=='A'||a[2]=='B') && (b[2]=='A'||b[2]=='B'))
            {
                cout<<1;
            }
            else if((a[2]=='B'||a[2]=='C') && (b[2]=='B'||b[2]=='C'))
            {
                cout<<1;
            }
            else cout<<0;
        }
        else cout<<0<<0;

    }
    else cout<<0<<0<<0;
    return 0;
}
