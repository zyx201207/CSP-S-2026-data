#include <bits/stdc++.h>
using namespace std;
int n;
long long pre[200005], a[200005];
char c[200005];
int cur1, cur2;
struct dat
{
    long long x;
    char ch;
}e1[200005], e2[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        pre[i] = pre[i - 1] + a[i];
    }
    long long mid = (pre[n] + 1) / 2, mid1 = mid + 1;
    int idx = lower_bound(pre + 1, pre + n + 1, mid) - pre;
    int idx1 = lower_bound(pre + 1, pre + n + 1, mid1) - pre;
    long long sum1 = 0, sum2 = 0;
    if (pre[n] & 1)
    {
        for (int i = 1; i < idx; i++)
        {
            e1[++cur1].x = a[i], e1[cur1].ch = c[i];
            sum1 += a[i];
        }
        for (int i = n; i > idx; i--)
        {
            e2[++cur2].x = a[i], e2[cur2].ch = c[i];
            sum2 += a[i];
        }
        if (mid - pre[idx - 1] - 1 > 0)
        {
            e1[++cur1].x = mid - pre[idx - 1] - 1, e1[cur1].ch = c[idx];
            sum1 += mid - pre[idx - 1] - 1;
        }
        if (pre[idx] - mid > 0)
        {
            e2[++cur2].x = pre[idx] - mid, e2[cur2].ch = c[idx];
            sum2 += pre[idx] - mid;
        }
    }
    else
    {
        for (int i = 1; i < idx; i++)
        {
            e1[++cur1].x = a[i], e1[cur1].ch = c[i];
            sum1 += a[i];
        }
        for (int i = n; i > idx1; i--)
        {
            e2[++cur2].x = a[i], e2[cur2].ch = c[i];
            sum2 += a[i];
        }
        if (mid - pre[idx - 1] > 0)
        {
            e1[++cur1].x = mid - pre[idx - 1], e1[cur1].ch = c[idx];
            sum1 += mid - pre[idx - 1];
        }
        if (pre[idx1] - mid1 + 1 > 0)
        {
            e2[++cur2].x = pre[idx1] - mid1 + 1, e2[cur2].ch = c[idx1];
            sum2 += pre[idx1] - mid1 + 1;
        }
    }
    int pos1 = 1, pos2 = 1;
    long long ans = 0;
    while (pos1 <= cur1 && pos2 <= cur2)
    {
        if (e1[pos1].x == e2[pos2].x)
        {
            if (e1[pos1].ch != e2[pos2].ch)
            {
                ans += e1[pos1].x;
            }
            pos1++, pos2++;
        }
        else if (e1[pos1].x > e2[pos2].x)
        {
            if (e1[pos1].ch != e2[pos2].ch)
            {
                ans += e2[pos2].x;
            }
            e1[pos1].x -= e2[pos2].x;
            pos2++;
        }
        else
        {
            if (e1[pos1].ch != e2[pos2].ch)
            {
                ans += e1[pos1].x;
            }
            e2[pos2].x -= e1[pos1].x;
            pos1++;
        }
    }
    cout << ans << endl;
    return 0;
}