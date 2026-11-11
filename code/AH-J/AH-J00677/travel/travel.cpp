#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int cnt=0;
    for(int i=0;i<a.size();i++)
        if(a[i]==c[i])
            cnt++;
    if(cnt==a.size())
        cout<<1;
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    cnt=0;
    for(int i=0;i<b.size()-1;i++)
        if(b[i]==d[i])
            cnt++;
    if(cnt==b.size()-1)
        cout<<1;
    else
    {
        cout<<0<<0<<0;
        return 0;
    }
    int n=b.size()-1;
    if((b[n]=='F'||b[n]=='D'&&d[n]!='F'&&d[n]!='D')||(d[n]=='F'||d[n]=='D'&&b[n]!='F'&&b[n]!='D'))
    {
        cout<<0<<0;
        return 0;
    }
    else if(b[n]=='F'||b[n]=='D'&&d[n]=='F'||d[n]=='D')
        cout<<1<<1;
    else
    {
        cout<<1;
        if(b[n]=='B'||d[n]=='B')
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
