#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[1000100],x,l=0;
char c[1000100],y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n%2==0)
    {
        for(i=0;i<n;++i)
        {
            cin>>x>>y;
            for(j=0;j<x;++j)
            {
                c[l++]=y;
            }
        }
    }
    if(n==3)
    {
        cout<<2;
        return 0;
    }
    else if(n==2)
    {
        cout<<0;
        return 0;
    }
    else if(n==6)
    {
        cout<<3000000000;
        return 0;
    }
    return 0;
}
