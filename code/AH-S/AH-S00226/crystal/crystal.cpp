#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,a[500105],cnt=1,l,r,qz[500005];
/*bool craft(long long x,long long y)
{
    long long sum=0;
    for(int i=x;i<=y;i++)
    {
        sum+=a[y]-a[i];
        if(sum>m)return 0;
    }
    return 1;
}*/
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
    l=1;
    r=2;
    while(l<=r)
    {
        if(a[r]*(r-l+1)-qz[r]+qz[l-1]<=m){cnt=max(r-l+1,cnt);r++;}
        else l++;
        if(r>n)break;
    }
    /*l=1;
    r=n;
    while(l<r)
    {
        if(a[r]*(r-l+1)-qz[r]+qz[l-1]<=m){cnt=max(r-l+1,cnt);break;}
        if(a[l+1]-a[l]>=a[r]-a[r-1])l++;
        else r--;
    }*/
    cout<<cnt;
    return 0;
}
