#include <iostream>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e5 + 5;
int n, m, head, a[N], b[N], ans[M];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        head = 0;
        for (int j = i; j <= n; j++)
        {
            bool f = 1;
            for (int k = 1; k <= head; k++)
            {
                if (b[k] == a[j])
                {
                    head = k;
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                b[++head] = a[j];
            }
        }
        for (int j = 1; j <= head; j++)
        {
            ans[b[j]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            b[i] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
