#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

struct node
{
    int a;
    char c;
} a[200005];

int s[200005];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].c;
        s[i] = s[i - 1] + a[i].a;
    }
    int nas = 0;
    for (int i = 1, j = n, pre = 0, suf = 0; i < j;)
    {
        // cout << pre << ' ' << suf << ' ' << i << ' ' << j << '\n';
        int add = min(a[i].a, a[j].a);
        pre += add, suf += add;
        a[i].a -= add, a[j].a -= add;
        if (a[i].c != a[j].c)
            nas += add;
        if (pre == s[i])
            i++;
        if (suf == s[n] - s[j - 1])
            j--;
    }
    cout << nas;
    return 0;
}