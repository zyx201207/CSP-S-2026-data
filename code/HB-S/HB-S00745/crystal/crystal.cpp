#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l=1,r=0,sum=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*(r-l+1);
        r++;
        while(sum>m)
        {
            sum-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}