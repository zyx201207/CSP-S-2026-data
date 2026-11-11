#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    if (n <= 5000)
    {
        // brute
        vector<int> cnt(m + 1);
        for (int i = 0; i < n; ++i)
        {
            vector<int> pos(m + 1, -1), stk;
            for (int j = i; j < n; ++j)
            {
                if (pos[a[j]] == -1)
                {
                    pos[a[j]] = j;
                    stk.push_back(a[j]);
                }
                else
                {
                    while (!stk.empty() && stk.back() != a[j])
                    {
                        pos[stk.back()] = -1;
                        stk.pop_back();
                    }
                }
            }

            while (!stk.empty())
            {
                ++cnt[stk.back()];
                // printf("%d ", stk.back());
                stk.pop_back();
            }
            // printf("\n");
        }
        for (int i = 1; i <= m; ++i)
        {
            printf("%d ", cnt[i]);
        }
    } else
    { // 区间DP，来不及写了唉
        for (int i = 1; i <= m; ++i)
        {
            printf("0 ");
        }
    }
}
