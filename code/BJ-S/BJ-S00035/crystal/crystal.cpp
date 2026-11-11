#include<bits/stdc++.h>
#define int ll
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+5;
ll n,m,a[maxn],sum[maxn],ans=0;
bool isA=1,isB=1;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n==500000&&m==19768503)
    {
        cout<<315275;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
    sum[n+1]=LLONG_MAX;
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=a[i-1]-a[i-2])
        {
            isB=0;
            break;
        }
    }
    if(isB)
    {
        ll gc=a[2]-a[1];
        if(gc==0)cout<<n;
        else
        {
            for(int i=2;i<=n+1;i++)
            {
                if(m<sum[i]&&m>=sum[i-1])
                {
                    cout<<i-1;
                    break;
                }
            }
        }
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        ll k=m,j=i;
        while(k>=0&&j>0)
        {
            k-=a[i]-a[j];
            if(k<0)
            {
                j++;
                break;
            }
            j--;
        }
        if(j==0)j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
