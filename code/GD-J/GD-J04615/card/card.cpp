#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;
int a[MAXN], ext[MAXN], ans[MAXN], top;
pair<int, int> stk[MAXN];
bool instk[MAXN];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n <= 500)
    {
        for (int i = 1; i <= n; i++)
        {
            stack<int> stk;
            memset(instk, 0, sizeof(instk));
            for (int j = i; j <= n; j++)
            {
                if (instk[a[j]])
                {
                    while (!stk.empty() && stk.top() != a[j])
                    {
                        instk[stk.top()] = false;
                        stk.pop();
                    }
                }
                else
                {
                    stk.push(a[j]);
                    instk[a[j]] = true;
                }
            }
            while (!stk.empty())
            {
                ans[stk.top()]++;
                stk.pop();
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cout << ans[i] << ' ';
        }
        return 0;
    }
    for (int i = n; i >= 1; i--)
    {
        // 弹出的时候就知道当前元素在栈里面存在了多久
        if (ext[a[i]])
        {
            while (top && stk[top].second < ext[a[i]])
            {
                ans[stk[top].first] += stk[top].second - i;
                stk[top].first = stk[top].second = 0;
                top--;
            }
            if (stk[top].first != a[i])
            {
                stk[++top] = {a[i], i};
            }
            // 对于stk的每一个元素都加上1
        }
        else
        {
            stk[++top] = {a[i], i};
        }
        ext[a[i]] = i;
    }
    while (top)
    {
        ans[stk[top].first] += stk[top].second;
        top--;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
