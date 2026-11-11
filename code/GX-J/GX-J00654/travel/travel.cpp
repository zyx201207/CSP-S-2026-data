#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else
    {
        cout<<0000;
        return 0;
    }
    if(b[1]=='0'&&d[1]=='0')
    {
        if(b[1]-'0'==d[1]-'0') cout<<1;
        else
        {
            cout<<000;
            return 0;
        }
    }
    else if(b[1]=='1'&&d[1]=='1')
    {
        if((b[1]-'0'*10+b[2]-'0')==(d[1]-'0'*10+d[2]-'0)) cout<<1;
        else
        {
            cout<<000;
            return 0;
        }
    }
    else
    {
        cout<<000;
        return 0;
    }
    if(b[1]=='0'&&d[1]=='0')
    {
           if((b[1]-'0'==d[1]-'0')&&(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))) cout<<1;
           else cout<<0;
    }
    else if(b[1]=='1'&&d[1]=='1')
    {
        if((b[1]-'0'*10+b[2]-'0')==(d[1]-'0'*10+d[2]-'0'))&&(((b[3]=='A'||b[3]=='B'||b[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C'))||((b[3]=='D'||b[3]=='F')&&(d[3]=='D'||d[3]=='F'))) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D') cout<<1;
    else cout<<0;
    return 0;
}
