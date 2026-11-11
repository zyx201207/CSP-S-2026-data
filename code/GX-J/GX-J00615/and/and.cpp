#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],d=0,x=0,z=900000;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    x=n;
    for(int i=1;i<=m;i++)
    {
        if(a[x]!=d)
        {
            d=a[x];
            if(d<z)
            {
                z=d;
            }
        }
        x--;
    }
    cout<<z;
    return 0;
}
