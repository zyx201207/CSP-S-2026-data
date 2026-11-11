#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[500010];
int d[500010];
int ans = 0;

int find(int num)
{
    int l = 1,r = num - 1;
    int ans = -1;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if((num - mid) * a[num] - (d[num - 1] - d[mid - 1]) <= m)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(ans == -1)
    {
        return 1;
    }
    else
    {
        return num - ans + 1;
    }
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++)
    {
        d[i] = d[i - 1] + a[i];
        ans = max(ans,find(i));
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
