#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200010][50];
bool b[200010] = {true};

void ten_two(int num, int b)
{
    int t = b;
    for (int i = 1; t; i++)
    {
        a[num][i] = t % 2;
        t /= 2;
    }
}

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        ten_two(i, c);
    }
    bool first = true;
    for (int i = 31; i >= 1; i--)
    {
        int flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if(!b[j]) continue;
            if (a[j][i] == 1)
            {
                flag++;
            }
            else
            {
                b[j] = false;
            }
        }
        if (flag < m && first)
        {
            memset(b, true, sizeof(b));
        }
        else if (flag >= m)
        {
            first = false;
            ans += pow(2, i - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
