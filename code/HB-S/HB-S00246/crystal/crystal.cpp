#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m;
const int N = 5e5 + 5;

long long a[N];
int ans = 1;

void solve1()
{
    // set<int,greater<int>()> a;
    unordered_map<int, int> cnt;

    for (int i = 1; i <= n; ++i)
        cnt[a[i]]++;
    for (int i = n; i > ans; --i)
    {
        unsigned long long k = m;
        sort(a + 1, a + 1 + n);
        int pos = cnt[a[i]];
        for (int j = i - cnt[a[i]]; j >= 1 && k > 0; j -= cnt[a[j]])
            if ((a[i] - a[j]) * cnt[a[j]] > k)
                pos += k / (a[i] - a[j]), k = 0;
            else
                pos += cnt[a[j]], k -= (a[i] - a[j]) * cnt[a[j]];

        ans = max(ans, pos);
    }
    cout << ans;
    return;
}

void solveA()
{

    // unsigned long long l = 1, r = min(n - 1, (unsigned long long) sqrt(m) + 1)
    if (m < 1)
    {
        cout << 1;
        return;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        unsigned long long cnt = (1 + n - i) / 2 * (n - i);
        if (cnt > m)
        {
            cout << n - i;
            return;
        }
    }
    cout << n;
    return;
}

void solveB()
{
    int gc = a[2] - a[1];
    if (m < gc)
    {
        cout << 1;
        return;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        unsigned long long cnt = gc * (n - i) / 2 * (1 + n - i);
        if (cnt > m)
        {
            cout << n - i;
            return;
        }
    }
    cout << n;
    return;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    bool flagA = true, flagB = true;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], flagA = (a[i] == i && flagA), flagB = ((i >= 3 && a[i] - a[i - 1] == a[i - 1] - a[i - 2] || i < 3) && flagB); //判断特殊性质A与B
    if (flagA)
        solveA();
    else if (flagB)
        solveB();
    else
        solve1(); //O(n^2) 暴力算法
}