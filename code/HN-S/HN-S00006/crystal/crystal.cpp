#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N];
long long sum[N];
long long ans = 0;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //对能量进行排序
    sort(a + 1, a + n + 1);

    for (int i = 1 ; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        //在当前的i以内，计算最大可以到多大能量
        while ((ans < i) && (sum[i] - sum[i - ans - 1] + m >= (ans + 1) * a[i])) ans++;
    }

    cout << ans << endl;

    return 0;
}
