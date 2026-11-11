#include <bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans=a[n];
    m--;
    for(long long i=n-1;i>=1;i--)
    {
        if(m!=0)
        {
            ans=ans&a[i];
            m--;
        }
    }
    cout<<ans;
    return 0;
}
