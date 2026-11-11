#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500050],s[500050],n,m;
int ef(int x)
{
    int l=1,r=x;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(s[x]-s[mid-1]+m>=(x-mid+1)*a[x]) r=mid;
        else l=mid+1;
    }
    return r;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int maxn=0;
    for (int i=1;i<=n;i++) maxn=max(maxn,i-ef(i)+1);
    cout<<maxn;
    return 0;
}
