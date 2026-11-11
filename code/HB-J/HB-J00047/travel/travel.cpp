#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a==b) cout<<1;
    else cout<<0;
    if(y[0]==b[0]&&y[1]==b[1])
    {
        cout<<1;
        if(y[2]>='A'&&y[2]<='C'&&b[2]>='A'&&b[2]<='C') cout<<1;
        else if(b[2]>='B'&&y[2]>='B') cout<<1;
        else cout<<0;
    }
    else cout<<0;
    if(abs(b[2]-y[2)])==1) cout<<1;
    else cout<<0;
    return 0;
}
