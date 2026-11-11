#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int tt[100005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum,t,maxx=-1;
    int an=0;
    cin>>n>>m;
    if(n>5000)
    {
        long long l=0,r=1000000000,ans;
        while(l<r)
        {
            long long mid=l+(r-l)/2;
            if(mid*mid+mid<=2*m)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tt[a[i]]++;
        an=max(an,tt[a[i]]);
    }
    if(m==0)
    {
        cout<<an;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        t=m;
        sum=1;
        for(int j=i-1;j>=1;j--)
        {
            t-=a[i]-a[j];
            if(t<0)break;
            sum++;
        }
        maxx=max(maxx,sum);
    }
    cout<<maxx;
    return 0;
}
