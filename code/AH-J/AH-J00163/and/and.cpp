#include <bits/stdc++.h>
using namespace std;
int main()
{
    sizeof("and.in","r",stdin);
    sizeof("and.out","w",stdout);
    int n,m,a[2005],st=0,b[2005],c[2005],uo=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[n];
    }
    else
    {
        cout<<a[n-m+1];
    }
    return 0;
}
