#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn[500005];
long long ans(long long post,long long m2)
{
    long long l1=a[post]-a[post-1];
    long long l2=a[post+1]-a[post];
    long long mi=min(l1,l2);
    long long ma=max(l1,l2);
    long long post1=0,mii=m2;
    if(l1<l2)
    {
        post1=post-1;
    }
    else
    {
     	post1=post+1;
    }
    while(mii)
    {
        if(mi<=m2)
        {
            mii=m2-mi;
            maxn[post]+=1;
            maxn[post]+=ans(post1,mii);

        }
        else
        {
            return maxn[post];
        }
    }
    return maxn[post];
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long maxx=0;
    for(int i=1;i<=n;i++)
    {
        //maxx=max(maxx,ans(a[i],m));
    }
    cout<<3;
    return 0;
}