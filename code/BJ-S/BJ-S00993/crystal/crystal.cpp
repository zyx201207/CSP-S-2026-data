#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
long long n,m,a[maxn];
long long cnt,sum[maxn];

long long bin(int i)
{
    int l=1,r=i;
    long long ans;

    while(l<=r)
    {
        int mid=(l+r)/2;
        long long s=sum[i]-(mid-1)*(a[i]-a[mid])-sum[mid];

        if(s<=m)
        {
            ans=i-mid+1;
            r=mid-1;
        }
        else
            l=mid+1;
    }

    return ans;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)
        sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);

    for(int i=1; i<=n; i++)
    {
        cnt=max(cnt,bin(i));
    }
    cout<<cnt;

    return 0;
}
