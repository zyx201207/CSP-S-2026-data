#include<bits/stdc++.h>
using namespace std;
int n,a[500010];
long long m,ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int j=n;
    for(int i=n;i>=2;i--)
    {
        while(j&&m>=a[i]-a[j])
        {
            m-=a[i]-a[j];
            j--;
        }
        ans=max(1ll*(i-j),ans);
        if(j<1) break;
        m+=(i-j-1)*(a[i]-a[i-1]);
    }
    ans=max(ans,1ll);
    cout<<ans;
    return 0;
}