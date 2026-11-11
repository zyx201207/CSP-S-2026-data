#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l,n,s=1;
    string a,x[100];
    bool d=1;
    cin>>l;
    for(int i=1;i<=l;i++)
    {
        cin>>n>>a;
        for(int j=1;j<=n;j++)
        {
            x[s]=a;
            s++;
        }
    }
    for(int i=2;i<=s;i++)
    {
        if(a[i-1]!=a[i])
        {
            d=0;
        }
    }
    if(d==1)
    {
        cout<<"0";
    }
    else
    {
        cout<<n;
    }
    return 0;
}
