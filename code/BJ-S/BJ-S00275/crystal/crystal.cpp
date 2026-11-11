#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long an=0,l=n,m1=0;
    for(int i=n;i>=1;i--)
    {
        m1+=a[l]-a[i];
        while(m1>m)
        {
            l--;
            m1=m1-(l-i+1)*(a[l+1]-a[l]);
            an--;
        }
        an++;
        ans=max(an,ans);
    }
    cout<<ans;
    return 0;
}
