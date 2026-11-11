#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N = 5e5+10;

int n;
ll m,a[N],s[N];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i] = s[i-1] + a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int pos=i-1,l=0,r=i-1;
        while(l <= r)
        {
            int mid = (l+r)>>1;
            // cerr << i << ' ' << mid << ' ' << a[i]*(i-mid) << ' ' << (s[i]-s[mid]) << '\n';
            if(a[i]*(i-mid) - (s[i]-s[mid]) <= m)
            {
                pos = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        ans = max(ans,i-pos);
    }
    cout << ans;
}