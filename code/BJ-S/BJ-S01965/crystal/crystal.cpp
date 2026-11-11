#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010100],s[1010100];
bool check(long long x)
{
    for(int i=1;i<=n-x+1;i++)
    {
        if(a[i+x-1]*x-s[i+x-1]+s[i-1]<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}
