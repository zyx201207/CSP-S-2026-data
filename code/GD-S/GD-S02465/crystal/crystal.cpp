#include<bits/stdc++.h>
using namespace std;
const int N=8e5+7;
long long n,m,i,j,k,qzh[N],a[N];
long long chr(long long l,long long r)
{
    return qzh[r+1]-qzh[l];
}
long long rf(long long w)
{
    long long l=0,r=w,mid,ans=w;
    for(;r>=l;)
    {
        mid=(l+r)/2;
        if((w-mid+1)*a[w]-chr(mid,w)<=m)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return (w-ans+1);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    qzh[0]=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++) qzh[i+1]=qzh[i]+a[i];
    long long ans=0;
    for(i=0;i<n;i++)
    {
        ans=max(ans,rf(i));
    }
    cout<<ans;
    return 0;
}
//这集神了，连续两年T1都是贪心
