#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N],sum[N];
bool check(int mid)
{
    int mi=0x3f3f3f3f3f3f3f3f;
    for(int i=mid;i<=n;i++)
    {
        mi=min(mi,mid*a[i]-sum[i]+sum[i-mid]);
    }
    return mi<=m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int l=1,r=n+1;
    while(l+1!=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l;
}
/*
只能增加。
二分答案一下，然后得先排个序，然后是不是求一下min
*/
