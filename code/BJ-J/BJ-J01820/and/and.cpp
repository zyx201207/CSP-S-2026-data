#include<bits/stdc++.h>
using namespace std;
int n, a[200005], m, maxn;
bool vis[200005];
void dfs(int k, int sum, int y)
{
    if(k == m + 1)
    {
        maxn = max(sum, maxn);
        return;
    }
    for(int i = y + 1;i <= n;i++)
    {
        if(k == 1)
        {
            dfs(k + 1, a[i], i);
        }
        else
            dfs(k + 1, sum & a[i], i);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >>a[i];
    }
    dfs(1, 0, 0);
    cout << maxn;
    return 0;
}
