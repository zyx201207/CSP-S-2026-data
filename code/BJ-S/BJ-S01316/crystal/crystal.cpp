#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N = 5e5+5;
int a[N];
int n,m;
bool ch(int k)
{
    int xk = a[k];
    int tans = 0ll;
    for(int i = n-k+1;i<=n;i++) tans += a[n]-a[i];
    if(tans <= m) return 1;
    for(int i = n-1;i>=k;i--)
    {
        tans = tans - (a[i+1]-a[i]) - (k-1ll) * (a[i+1]-a[i]) + (a[i] - a[i-k+1]);
        if(tans <= m) return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l = 1,r = n; int ans = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(ch(mid))
        {
            l = mid+1;
            ans = mid;
        }
        else r = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
