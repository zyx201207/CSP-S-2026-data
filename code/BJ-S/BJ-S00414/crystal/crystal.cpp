#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],n,m;
int dif[500010],sum[500010];
int aan(int i,int j)
{
    return (dif[j-1]-dif[i-1])-(sum[j-1]-sum[i-1])*(i-1);
}
bool ifcan(int l)
{
    for(int i=1;i<=n-l+1;i++)
    {
        int aaa=aan(i,i+l-1);
        if(aaa<=m)
        {
            int tmp=a[i+l-1];
            int mm=m;
            mm-=aaa;
            mm%=l;
            if(mm!=0)
            {
                if(l!=n)return 1;
                else return 0;
            }
            else return 1;

        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)dif[i]=a[i+1]-a[i],sum[i]=sum[i-1]+dif[i];
    for(int i=1;i<n;i++)dif[i]=dif[i-1]+dif[i]*i;
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(ifcan(mid))
        {
            l=mid;
        }
        else r=mid-1;
    }

    cout<<l;
    return 0;
}
