#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 5e5+5;
int n;
LL m,res,a[N],s[N];
bool check(LL x,LL mid)
{
    return m >= (x-mid)*a[x]-(s[x-1]-s[mid-1]);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++) s[i] = s[i-1]+a[i];
    for(int i = 1;i<=n;i++)
    {
        LL l = 1,r = i-1,ans = -1;
        while(l <= r)
        {
            LL mid = l+r>>1;
            if(check(i,mid))
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        if(ans != -1) res = max(res,i-ans+1);
    }
    cout << res << '\n';
    return 0;
}