#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],b[N],ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j,l,r;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)   b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
    l=1;r=1;
    while(r<=n)
    {
        while(b[r]-b[l]-(l-1)*(a[r]-a[l])>m)
            l++;
        ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans;
    return 0;
}
