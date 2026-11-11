#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int x;
    int a;
} a[200005];

bool cmp(node x, node y)
{
    if (x.x != y.x) return x.x > y.x;
    else return x.a > y.a;
}

bool c(int x, int y)
{
    return x > y;
}

int b[200005];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].a;
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0, r = a[i].a;
        while (r != 0)
        {
            sum += r % 2;
            r /= 2;
        }
        a[i].x = sum;
        b[i] = a[i].a;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, c);
    //for (int i = 1; i <= n; ++i) cout << a[i].a << " ";
    //cout << "\n";
    int ans1 = a[1].a, ans2 = b[1];
    for (int i = 2; i <= m; ++i) ans1 &= a[i].a;
    for (int i = 2; i <= m; ++i) ans2 &= b[i];
    cout << max(ans1, min(ans2, b[m]));
    return 0;
}
