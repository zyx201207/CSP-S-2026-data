#include <bits/stdc++.h>
using namespace std;

int n, m;

long long a[200010];

bool cmp(int x, int y)
{
    return x > y;
}

long long ans = 0;

/*void dfs(int step, long long ret)
{
    if(step > m)
    {
        cout << ans << "#" << endl;
        ans = max(ans, ret);
        return ;
    }
    for(int i = 1;i <= n;i++)
    {
        dfs(step + 1, ret & a[i]);
    }
}*/

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n;
    /*if(n <= 20)
    {
        dfs(1, a[n]);
        cout << ans << endl;
    }*/
    for(int i = 1;i <= n;i++)
    {
        cout << n << " ";
    }
    return 0;
}