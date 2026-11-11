#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN],s[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin >> n;
    long long m;
    cin >>m;
    for (int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=1;
    for (int i=2;i<=n;i++)
    {
        int l=1,r=i,anss=i;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if ((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m)
            {
                anss=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,i-anss+1);
    }
    cout << ans << "\n";
    return 0;
}
