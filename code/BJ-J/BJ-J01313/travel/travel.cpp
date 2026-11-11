#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a1,b1,a2,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<"1";
    a1=s1.substr(0,2);
    b1=s1.substr(2,1);
    a2=s2.substr(0,2);
    b2=s2.substr(2,1);
    if(a1!=a2)
    {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<"1";
    if(b1>b2)
    {
        string t;
        t=b1;
        b1=b2;
        b2=t;
    }
    if(b1<="C"&&b2>="D")
    {
        cout<<"00"<<endl;
        return 0;
    }
    cout<<"1";
    if(b1=="A"&&b2=="C")
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<"1"<<endl;
    return 0;
}
