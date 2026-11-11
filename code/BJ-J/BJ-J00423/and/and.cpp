#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=1,x=31;
    cin>>n>>m;
    long long a[n+1],sum=0;
    bool b[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=30;i++)ans<<=1,ans++;
    while(x--)
    {
        sum=0;
        for(int i=1;i<=n;i++)
        {
            b[i]=0;
            if(a[i]&1<<x)b[i]=1,sum++;
        }
        if(sum>=m)break;
    }
    for(int i=1;i<=n;i++)
        if(b[i]&&m!=0)m--,ans&=a[i];
    cout<<ans;
    return 0;
}
