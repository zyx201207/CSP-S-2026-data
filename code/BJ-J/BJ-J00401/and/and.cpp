#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],c[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long cnt=1;
    for(int i=n;i>=n-m;i--)
    {
        for(int j=i-1;j>=n-m;j--)
        {
            c[cnt]=a[i]&a[j];
            cnt++;
        }
    }
    long long maxx=-1;
    for(int i=1;i<=cnt;i++)
    {
        if(c[cnt]>maxx)
        {
            maxx=c[cnt];
        }
    }
    if(m==2)
    {
        cout <<cnt*3;
    }
    else
    {
        cout <<cnt;
    }
    return 0;
}
