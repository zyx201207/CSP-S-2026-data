#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a[0]==b[0]&&a[1]==b[1])
    {
        cout<<'1';
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(a1[0]==b1[0]&&a1[1]==b1[1])  cout<<'1';
    else
    {
        cout<<"000";
        return 0;
    }
    if((a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C')||(a1[2]>='D'&&a1[2]<='F'&&b1[2]>='D'&&b1[2]<='F'))  cout<<'1';
    else
    {
        cout<<"00";
        return 0;
    }
    if(a1[2]>='A'&&a1[2]<='C')
    {
        if(abs((a1[2]-'0')-(b1[2]-'0'))==1) cout<<'1';
        else cout<<'0';
    }
    else
    {
        cout<<'1';
    }
    return 0;
}
