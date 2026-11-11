//GZ-J00454 华东师范大学附属贵阳学校 蒋泽赟
#include <bits/stdc++.h>
using namespace std;

pair<int, char> ls[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        ls[i] = {a, b};
    }
    int l = 1, r = n;
    long long cnt = 0;
    while (l < r)
    {
        if (ls[l].first < ls[r].first)
        {
            ls[r].first -= ls[l].first;
            if (ls[l].second != (ls[r].second)) cnt += ls[l].first * 1ll;
            l++;
        }
        else if (ls[l].first > ls[r].first)
        {
            ls[l].first -= ls[r].first;
            if (ls[l].second != (ls[r].second)) cnt += ls[r].first * 1ll;
            r--;
        }
        else
        {
            if (ls[l].second != (ls[r].second)) cnt += ls[r].first * 1ll;
            r--;
            l++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
