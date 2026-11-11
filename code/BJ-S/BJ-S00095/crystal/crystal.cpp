#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],Max;
bool flag=true;
long long sum(long long i,long long k)
{
    long long ans=0;
    for(long long x=i;x>i-k;x--)
    {
        ans+=abs(a[x]-a[i]);
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long cha=abs(a[2]-a[1]);
    for(long long i=3;i<=n;i++)
    {
        if(cha!=a[i]-a[i-1])
        {
            flag=false;
        }
    }
    if(flag==true)
    {
        Max=1;
        long long Sum=0;
        for(long long i=1;;i++)
        {
            Sum+=i;
            long long now=Sum*cha;
            if(now<=m)
            {
                Max++;
            }
            else
            {
                break;
            }
        }
        cout<<Max;
        return 0;
    }
    for(long long k=1;k<=n;k++)
    {
        long long ans=20000000000;
        for(long long i=n;i>=k;i--)
        {
            ans=min(ans,sum(i,k));
        }
        if(ans<=m)
        {
            Max=k;
        }
    }
    cout<<Max;
    fclose(stdin);
    fclose(stdout);
    return 0;
}