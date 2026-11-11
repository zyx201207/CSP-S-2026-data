#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string ans;
    if(a==c)
        ans.push_back('1');
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b.substr(0,2)==d.substr(0,2))
        ans.push_back('1');
    else
    {
        cout<<ans<<"000";
        return 0;
    }
    if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
        ans.push_back('1');
    else
        ans.push_back('0');
    if(b[2]=='A')
    {
        if(d[2]=='B')
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    else if(b[2]=='B')
    {
        if(d[2]=='A'||d[2]=='C')
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    else if(b[2]=='C')
    {
        if(d[2]=='B')
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    else if(b[2]=='D')
    {
        if(d[2]=='F')
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    else if(b[2]=='F')
    {
        if(d[2]=='D')
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    cout<<ans;
    return 0;
}
