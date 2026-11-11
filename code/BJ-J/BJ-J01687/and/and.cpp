#include <iostream>
using namespace std;

int n , m , a[200005] , vis[200005] , ans = 0;
void dfs(int step , int sum)
{
    if (step > m)
    {
        ans = max(ans , sum);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int x = sum & a[i];
            vis[i] = 1;
            dfs(step + 1 , sum & a[i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1 , 2147483647);
    cout << ans << endl;
    return 0;
}
