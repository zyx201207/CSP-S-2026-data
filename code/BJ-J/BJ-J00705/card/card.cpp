#include <iostream>
using namespace std;
int a[300005];
int ans[500005];
int box[500005];
int boxc[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        box[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int last = 0;
        for (int j = 1; j <= m; j++)
        {
            boxc[j] = box[j];
        }
        for (int j = i; j <= n; j++)
        {
            boxc[a[j]]--;
            if (last != 0)
            {
                if (last == a[j])
                {
                    last = 0;
                    if (boxc[a[j]] >= 1)
                    {
                        last = a[j];
                    }
                    else ans[a[j]]++;
                    continue;
                }
                else continue;
            }
            else if (boxc[a[j]] >= 1)
            {
                last = a[j];
            }
            else
            {
                ans[a[j]]++;
            }
        }
        box[a[i]]--;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
