#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[200010],ans;
void dfs(ll sum,ll idx,ll cnt)
{

    if(cnt > m)
    {
        ans = max(ans,sum);
        return;
    }
    for(int i = idx;i <= n;i++)
    {
        dfs(sum | a[i],idx + 1,cnt + 1);
    }
    return;

}
int main()
{   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    dfs(1,1,0);
    cout << ans;
}
