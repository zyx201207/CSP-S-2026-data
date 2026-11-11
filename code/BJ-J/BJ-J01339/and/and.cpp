#include <iostream>
using namespace std;
long long a[200005];
long long ans = 0;
int n,m;
void dfs(int k,int c,long long res)
{
    if (k == m)
    {
        ans = max(res,ans);
        return;
    }
    if (c > n)
    {
        return;
    }
    if (k == 0)
    {
        dfs(k + 1,c + 1,a[c]);
        dfs(k,c + 1,res);
    }
    else
    {
        dfs(k + 1,c + 1,res & a[c]);
        dfs(k,c + 1,res);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n>>m;
    cin >> a[1];
    long long and1= a[1];
    long long maxn = a[1];
    for (int i = 2;i <= n; i++)
    {
        cin >>a[i];
        maxn = max(maxn,a[i]);
        and1 = and1 & a[i];
    }
    if (n <= 20)
    {
        dfs(0,1,0);
        cout << ans;
    }
    else if (m == 1)
    {
        cout << maxn;
    }
    else if (m == n)
    {
        cout <<and1;
    }
    else if (m == 2)
    {
        long long ans2 = 0;
        for (int i= 1; i<= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans2 = max(ans2,a[i]&a[j]);
            }
        }
        cout << ans2;
    }
    return 0;
}