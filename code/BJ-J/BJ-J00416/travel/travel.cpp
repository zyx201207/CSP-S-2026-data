#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    bool flag=0;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    char x=b[2],y=d[2];
    if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
    else cout<<0;
    if(b[0]==d[0]&&b[1]==d[1])
    {
        if('A'<=x&&x<='C')
        {
            if('A'<=y&&y<='C')
            {
                cout<<1;
                flag=1;
            }
            else cout<<0;
        }
        else
        {
            if(y=='D'||y=='F')
            {
                cout<<1;
                flag=1;
            }
            else cout<<0;
        }
    }
    else cout<<0;
    if(x=='F') x='E';
    if(y=='F') y='E';
    if(abs(x-y)==1&&flag) cout<<1;
    else cout<<0;
    return 0;
}
