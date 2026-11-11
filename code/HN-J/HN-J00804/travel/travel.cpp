#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int i;
string b;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>a>>i>>b;
    if(n==i)
    {
       cout<<1;

    }
    else{
        cout<<"0000";
        return 0;
    }
    if(a[0]==b [0]&&a[1]==b[1])
    {
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(a[2]<=67&&b[2]<=67)
    {
        cout<<1;
    }
    else if(a[2]<=69&&b[2]<=69)
    {
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(a[2]-b[2])==1)
    {
        cout<<1;
    }
    else{cout<<"0";}

    return 0;
}
