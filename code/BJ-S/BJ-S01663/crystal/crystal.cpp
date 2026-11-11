#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans;
inline int Q(int x)
{
    int l=0,r=x-1;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m) r=mid-1;
        else l=mid;
    }//last undot
    return l;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) 
    {
        s[i]=s[i-1]+a[i];
        ans=max(ans,i-Q(i));
    }
    cout<<ans<<"\n";
    return 0;
}