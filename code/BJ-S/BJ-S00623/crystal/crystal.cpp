#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,a[500005],need[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)
    {
        if(need[i - 1] < m || (need[i - 1] == m && a[i] == a[i - 1]))
            need[i] = need[i - 1] + (i - 1) * (a[i] - a[i - 1]);
        else
        {
            ans = i - 1;
            break;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//37min T1
