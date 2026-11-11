#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct node
{
    int val, cnt, dep;
    bool operator <(const node &nxt) const
    {
        if(val == nxt.val) return cnt > nxt.cnt;
        return val < nxt.val;
    }
};

int n, m, a[N], maxn = 0;
int sum[N];
priority_queue<node> que;
map<int, int> mp;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int c = 1;

    for(int i = 1;i <= 30;++ i)
    {
        mp[c - 1] = 1;
        c *= 2;
    }

    cin >> n >> m;

    int s = 0;

    for(int i = 1;i <= n;++ i)
    {
        cin >> a[i];
        if(mp[a[i]]) s ++;
        que.push(node{a[i], 1, i});
    }

    if(n == m)
    {
        maxn = a[1];

        for(int i = 2;i <= n;++ i)
        {
            maxn &= a[i];
        }

        cout << maxn;

        return 0;
    }

    if(m == 1)
    {
        for(int i = 1;i <= n;++ i)
        {
            maxn = max(maxn, a[i]);
        }

        cout << maxn;

        return 0;
    }


    if(m == n - 1)
    {
        maxn = a[1];
        for(int i = 2;i <= n;++ i)
        {
            sum[i] = maxn;
            maxn &= a[i];
        }
        maxn = a[n];
        for(int i = n - 1;i >= 1;-- i)
        {
            sum[i] &= maxn;
            maxn &= a[i];
        }
        maxn = 0;
        for(int i = 1;i <= n;++ i)
        {
            maxn = max(maxn, a[i]);
        }
        cout << maxn;

        return 0;
    }

    if(s == n)
    {
        sort(a + 1,a + 1 + n, cmp);

        cout << a[m];

        return 0;
    }

    while(que.size())
    {
        node now = que.top();
        que.pop();
        if(now.cnt == m)
        {
            maxn = max(maxn, now.val);
            continue;
        }
        if(n - now.dep < m - now.cnt)
        {
            continue;
        }
        for(int i = now.dep + 1;i <= n;++ i)
        {
            que.push(node{now.val & a[i], now.cnt + 1, i});
        }
    }

    cout << maxn;


    return 0;
}
