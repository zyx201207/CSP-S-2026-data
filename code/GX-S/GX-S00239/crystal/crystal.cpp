#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m, s = 0, c = 0, ms = 0;
    map<int, int> a;
    queue<int> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (pair<int, int> i : a)
    {
        if (i.second != 1)
        {
            s += i.second;
            continue;
        }
        while ((q.size() * i.first - c) > m)
        {
            c -= q.front();
            q.pop();
        }
        q.push(i.first);
        c += i.first;
        ms = max(ms, (int)q.size());
    }
    if (ms <= 1)
    {
        ms = 0;
    }
    s += ms;
    cout << s;
    return 0;
}
