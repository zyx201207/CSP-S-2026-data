#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s,t;
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(b.substr(0,2)!=d.substr(0,2))
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(b.substr(2,1)=="A"||b.substr(2,1)=="B"||b.substr(2,1)=="C")
        s=0;
    else
        s=1;
    if(d.substr(2,1)=="A"||d.substr(2,1)=="B"||d.substr(2,1)=="C")
        t=0;
    else
        t=1;
    if(s!=t)
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(b.substr(2,1)=="A"&&d.substr(2,1)=="B"||b.substr(2,1)=="B"&&d.substr(2,1)=="A"||b.substr(2,1)=="C"&&d.substr(2,1)=="B"||b.substr(2,1)=="B"&&d.substr(2,1)=="C"||b.substr(2,1)=="D"&&d.substr(2,1)=="F"||b.substr(2,1)=="F"&&d.substr(2,1)=="D")
        cout<<1;
    else
        cout<<0;
    return 0;
}
