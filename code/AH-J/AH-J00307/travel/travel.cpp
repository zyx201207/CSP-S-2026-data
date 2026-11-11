#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>c>>c1>>b>>d>>c2;
    if(a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(c==d)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(c1<'D'&&c2<'D'||c1>'C'&&c2>'C')
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(c1=='A'&&c2=='B'||c1=='B'&&c2=='C'||c1=='D'&&c2=='F'||c2=='A'&&c1=='B'||c2=='B'&&c1=='C'||c2=='D'&&c1=='F')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
