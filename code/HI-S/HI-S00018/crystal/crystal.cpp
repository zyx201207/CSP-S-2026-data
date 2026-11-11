#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
ll a[N];
ll pre[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin >> n >> m;
    for(int i = 1;i<=n;++i)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;++i)
    {
        pre[i] = pre[i-1]+a[i];
    }
    int ans = 0;
    for(int i = 1;i<=n;++i)
    {
        int j = i+1;
        while(a[j] == a[i])
        {
            ++j;
        }
        --j;
        int l = 1,r = i,res = i;
        while(l<=r)
        {
            int mid = l+r>>1;
            if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m)
            {
                res = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        ans = max(ans,i-res+j-i+1);
        i = j;
    }
    cout << ans;
    return 0;
}