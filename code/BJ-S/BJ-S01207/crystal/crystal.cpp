#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(long long i=n;i>=1;i--)
    {
        for(long long j=1;j<=n-i+1;j++)
        {
            if(i*a[j+i-1]-s[j+i-1]+s[j-1]<=m)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
