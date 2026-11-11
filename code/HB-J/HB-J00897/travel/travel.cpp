#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    if(c==cc)
        cout<<"1";
    else
        cout<<"0";

    if(s[0]==ss[0] and s[1]==ss[1])
        cout<<"1";
    else
        cout<<"0";

    if(s[2]-'A'<=2 and ss[2]-'A'<=2)
        cout<<"1";
    else if(s[2]-'A'>=3 and ss[2]-'A'>=3)
        cout<<"1";
    else
        cout<<"0";
    int a,b;
    a=s[2]-'A';
    b=ss[2]-'A';
    if(a!=5 and b!=5)
    {
        if(abs(a-b)==1)
            cout<<"1";
        else
            cout<<"0";
    }
    else
        if(a==3 or b==3)
            cout<<"1";
        else
            cout<<"0";
    return 0;
}
