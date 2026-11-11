#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans;
void f(int l,int r,int se)
{
    if(l>r)
    {
        return;
    }
    int mid=(l+r)/2;
    if(a[se]*(se-mid+1)-s[se]+s[mid-1]<=m)
    {
        ans=max(ans,se-mid+1);
        f(l,mid-1,se);
    }
    else
    {
        f(mid+1,r,se);
    }
    return;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        f(1,i,i);
    }
    cout<<ans;
    return 0;
}
