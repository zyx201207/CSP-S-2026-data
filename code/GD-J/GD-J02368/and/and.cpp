#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n), cnt(32);
    int bst = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];

        for (int j = 0; (1 << j) < a[i]; ++j)
        {
            if (a[i] & (1 << j))
            {
                ++ cnt[j];
                // printf("[%d] %d\n", i, j) ;

                if (cnt[j] >= m && j > bst)
                {
                    bst = j;
                }
            }
        }
    }

//    for (int i = 0; i < 32; ++ i) {
//    	cout << cnt[i] << " ";
//	}cout << "\n";

    sort(a.begin(), a.end(), greater<>());
    vector<int> b;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] & (1 << bst))
        {
            b.push_back(a[i]);
        }
    }
    int bs = b.size();
    while (bs > m)
    {
        int i, cnt;
        for (i = bst - 1; i >= 0; --i)
        {
            cnt = 0;
            for (int j = 0; j < bs; ++j)
            {
                // if ((b[j] > (1 << i)) && (b[j] & (1 << i)))
                if (b[j] & (1 << i)) {
                    ++ cnt;
                }
            }

            if (cnt >= m)
            {
                break;
            }
        }

        if (cnt >= m)
        {
            vector<int> c;
            for (int j = 0; j < bs; ++j)
            {
                if (b[j] & (1 << i))
                {
                    c.push_back(b[j]);
                }
            }
            b = c;
            bs = b.size();
        }

        bst = i;
        if (i < 0)
        {
            break;
        }
    }

    long long ans = b[0];
    for (int i = 1; i < bs; ++i)
    {
        ans = ans & b[i];
    }
    printf("%lld", ans);
}
