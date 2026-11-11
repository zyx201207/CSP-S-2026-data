#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n,m;
int a[N];
int s[N];

int get(int l,int r)
{
    int i = r;
    int ans = r;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) <= m)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans,i - get(1,i) + 1);
    cout << ans;
    return 0;
}
