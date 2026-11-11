#include<bits/stdc++.h>
using namespace std;
int a[600000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=0,ans=0,maxn=0;
    for(long long i=1;i<=n;i++)
    {
        sum=0;
        ans=1;
        for(long long j=i-1;j>=1;j--)
        {
            sum+=a[i]-a[j];
            if(sum>m)
            {
                break;
            }
            ans++;
        }
        if(maxn<ans)
        {
            maxn=ans;
        }
    }
    cout<<maxn;
    return 0;
}
