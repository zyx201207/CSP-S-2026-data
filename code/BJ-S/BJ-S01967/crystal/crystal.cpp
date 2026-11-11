#include <bits/stdc++.h>
using namespace std;
long long a[500002];
long long p[500002];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool flag=true;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]<m)
            flag=false;
    }
    if(flag==true)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]+a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if((long long)(i-mid)*a[i]-(p[i-1]-p[mid-1])<=m)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        //cout<<i<<' '<<l<<r<<endl;
        maxn=max(maxn,i-l+1);
    }
    cout<<maxn<<endl;
    return 0;
}
