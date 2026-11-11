#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long ans=0,sum=0,x;
    for(int i=1;i<=n;i++)
    {
        sum=1,x=m;
        for(int j=i-1;j>=1;j--)
        {
            x-=a[i]-a[j];
            sum++;
            if(x<0)sum--;
            if(x<=0)break;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
