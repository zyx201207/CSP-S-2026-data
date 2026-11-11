#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000005];
long long js(long long sum,int q)
{
    for(int i=q+1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            long long t=a[i]&a[j];
            sum=max(sum,t);
        }
    }
    return sum;
}
int main()
{
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long t=1,cnt=a[i];
        for(int j=1;j<=m;j++)
        {
            long long sum=0;
            sum=js(sum,i);
            ans=max(ans,sum);
        }
    }
    cout<<ans;
    return 0;
}
