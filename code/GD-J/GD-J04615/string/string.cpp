#include <bits/stdc++.h>
using namespace std;
pair<long long, char> a[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    int i = 1, j = n;
    long long ans = 0;
    while (i < j)
    {
        if (a[i].first <= a[j].first)
        {
            if (a[i].second != a[j].second)
                ans += a[i].first;
            a[j].first -= a[i].first;
            a[i].first = 0;
            if (a[j].first == 0)
                j--;
            i++;
        }
        else //(a[i].first>a[j].first)
        {
            if (a[i].second != a[j].second)
                ans += a[j].first;
            a[i].first -= a[j].first;
            a[j].first = 0;
            j--;
        }
    }
    cout << ans;
    return 0;
}