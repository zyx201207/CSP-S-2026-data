#include<bits/stdc++.h>
using namespace std;
long long a[500010],m,s[500010];
int n;
long long q(long long l,long long r)
{
    return a[r]*(r-l+1)-s[r]+s[l-1];
}
bool check(int len)
{
    for(int i=1;i+len-1<=n;i++)
    {
        int j=i+len-1;
        if(q(i,j)<=m)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
