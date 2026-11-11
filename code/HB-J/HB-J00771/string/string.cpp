#include<bits/stdc++.h>
using namespace std;
int n;
int a[300005];
int t[300005];
char c[300005];
long long sum[500005];
char c1[500005],c2[500005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        t[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        sum[2*n-i+1]=sum[2*n-i+2]+a[n-i+1];
    }
    sort(sum+1,sum+1+2*n);
    int len=unique(sum+1,sum+1+2*n)-sum-1;
    int now=1;
    for(int i=1;i<=len;i++)
    {
        if(a[now]==0)
        {
            now++;
        }
        a[now]-=sum[i]-sum[i-1];
        c1[i]=c[now];
    }
    now=1;
    for(int i=1;i<=len;i++)
    {
        if(t[n-now+1]==0)
        {
            now++;
        }
        t[n-now+1]-=sum[i]-sum[i-1];
        c2[i]=c[n-now+1];
    }
    long long ans=0;
    for(int i=1;i<=len;i++)
    {
        if(c1[i]!=c2[i])
        {
            ans+=sum[i]-sum[i-1];
        }
    }
    cout<<ans/2;
    return 0;
}