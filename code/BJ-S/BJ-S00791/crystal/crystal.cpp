#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],s[500005];
int n;
ll m;
bool chk(int x)
{
    for(int i=1;i<=n-x+1;i++) if(a[i+x-1]*x-(s[i+x-1]-s[i-1])<=m) return 1;
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=0,r=n;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(chk(mid)) l=mid;
        else r=mid-1;
    }cout<<l;
    return 0;
}