#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10, M = 3e5+10;
int last[M], ans[M], arr01[N], cnt[M], now[N];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr01[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        int num = 0;
        for (int j = i; j <= n; ++j)
        {
            if (cnt[arr01[j]])
            {
                for (int k = last[arr01[j]] + 1; k <= num; ++k)
                {
                    cnt[now[k]]--;
                    now[k] = 0;
                }
                num = last[arr01[j]];
            }
            else
            {
                cnt[arr01[j]]++;
                now[++num] = arr01[j];
                last[arr01[j]] = num;
            }
        }
        for (int j = 1; j <= num; ++j)
        {
            ans[now[j]]++;
            cnt[now[j]] = 0;
            now[j] = 0;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
