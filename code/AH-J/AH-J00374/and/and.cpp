#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, num[200005];
struct node
{
    long long num, cnt;
};
node a[200005];
bool cmp(node x, node y)
{
    return x.cnt > y.cnt;
}
long long twoj(long long x)
{
    long long sum;
    while (x > 0)
    {
        long long y = x % 2;
        if(y == 1)
        {
            sum++;
        }
        else
        {
            continue;
        }
        x /= 2;
    }
    return ans;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if(n <= 20)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> num[i];
        }
        sort(num + 1, num + n + 1);
        ans = num[n];
        for (int i = n - 1; i >= n - m + 1; i--)
        {
            ans &= num[i];
        }
        cout << ans;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].num;
        }
        for (int i = 1; i <= n; i++)
        {
            a[i].cnt = twoj(a[i].num);
        }
        sort(a + 1, a + n + 1, cmp);
        ans = a[1].num;
        for (int i = 2; i <= m; i++)
        {
            ans &= a[i].num;
        }
        cout << ans;
    }
    return 0;
}
