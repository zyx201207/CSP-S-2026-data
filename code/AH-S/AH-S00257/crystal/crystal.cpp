#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,ans;
int a[N],s[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i-1,res=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[i]*mid-(s[i-1]-s[i-mid-1])<=m) res=mid,l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,res+1);
    }
    cout<<ans;
    return 0;
}
