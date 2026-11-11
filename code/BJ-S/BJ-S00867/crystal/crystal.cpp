#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long x[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a+0,a+n);
    for(long long i=0;i<n-1;++i)
    {
        x[i]=a[i+1]-a[i];
    }
    long long maxn=0;
    for(long long i=0;i<n-1;++i)
    {
        long long cnt=0,sum=0;
        for(long long j=i;j<n-1;++j)
        {
            long long ans=(sum+(cnt+1)*x[j]);
            if(ans<=m)
            {
                sum=ans;
                cnt++;
            }
        }
        if(cnt>maxn) maxn=cnt;
    }
    cout<<maxn+1;

    return 0;
}
