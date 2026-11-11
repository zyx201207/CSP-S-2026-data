#include <bits/stdc++.h>
using namespace std;

long long n,a[500005],m;

long long  f(long long l,long long r)
{
    long long tot=0,ans=0;
    int mid=(l+r)/2;
    if(l==r)
    {
        long long tot=0,ans=0;
        for(int i=l;i>=1;i--)
        {
            if(tot+(a[l]-a[i])<=m)
            {
                tot+=a[l]-a[i];
                ans++;
            }
            else break;
        }
        return ans;
    }
   return max(f(l,mid),f(mid+1,r));
}

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

    cout<<f(1,n);
    return 0;
}
