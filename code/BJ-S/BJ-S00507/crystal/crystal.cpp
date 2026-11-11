#include<bits/stdc++.h>
using namespace std;
long long r_d()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long j=0;
    cin>>j;
    return j;
}
long long frd()
{
    long long g=0;
    cin>>g;
    return g;
}
long long n=r_d(),m=frd(),ans=1;
vector<long long> shu(n,0);
vector<long long> hee(n+2,0);
bool fang_fa(long long a,long long b)
{
    return a<b;
}
bool check(long long biao)
{
    for(long long i=biao-1;i<n;i++)
    {
        if(hee[i]-(i-biao<=0 ? 0:hee[i-biao])<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    for(long long i=0;i<n;i++)
    {
        cin>>shu[i];
        shu[i]=shu[i]+1e12;
    }
    sort(shu.begin(),shu.end(),fang_fa);
    for(long long i=0;i<n;i++)
    {
        hee[i]=(i==0 ? 0:hee[i-1])+i*(i==0 ? 0:shu[i]-shu[i-1]);
    }
    long long l=0,r=n-1,mid=0;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)==true)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
