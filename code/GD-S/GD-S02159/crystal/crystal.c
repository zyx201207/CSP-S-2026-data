#include <stdio.h>
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int a[500005];
    int c[500005][500005];

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // 跨度
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int b = a[j] - a[i];
            c[i][j] = b;
        }
    }

    if (a[0] == a[1])
    {
        int w; // 记录上一个数
        w = a[0];
        for (int i = 2; i < n; i++)
        {
            if (w = !a[i])
            {
                continue;
            }
        }
        printf("%d", n);
    }

    int p; // 最终相加数
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int num = 0; // 使用的次数
        p = a[i];

        if (c[i - 1][i] < m)
        {
            for (int j = i - 1; j < n; j--)
            {
                num = c[j][i] + c[j - 1][i];
                if (num == m)
                {
                    ans = i + 1;
                    if (a[i + 1] == p)
                    {
                        ans++;
                    }
                    printf("%d", ans);
                    return 0;
                }
            }
        }
    }

    return 0;
}
