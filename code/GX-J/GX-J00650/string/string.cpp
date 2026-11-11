#include <bits/stdc++.h>
using namespace std;
int n,x,y;
string a,b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    cin>>a>>b;
    if(n<=1)
    {
        cout<<"0";
    }
    else if(a==b)
    {
        cout<<"0";
    }
    else if(n<=2)
    {
        cin >>x>>y;
        if(x<y)
        {
            cout<<x;
        }
        if(y<x)
        {
            cout<<y;
        }
    }
    return 0;
}

