#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
void dfs(int now,int step,int sum)
{
    //cout << now << ' ' << step << ' ' << sum << endl;
    if(step > m) { ans = max(ans,sum); return; }
    if(now > n) return;
    dfs(now + 1,step + 1,sum & a[now]);
    dfs(now + 1,step,sum);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n <= 20)
    {
        dfs(1,1,(1 << 30) - 1);
        cout << ans << endl;
    }
    else if(m == 2)
    {
        for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) ans = max(ans,a[i] & a[j]);
        cout << ans << endl;
    }
    else
    {
        ans = (1 << 30) - 1;
        sort(a + 1,a + 1 + n);
        for(int i = 1,j = n;i <= m;i++,j--) ans &= a[j];
        cout << ans << endl;
    }
    return 0;
}
