#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int n, m, a[500000], cnt[300001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int ccnt[m + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]] += i + 1;
        ccnt[a[i]]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int cccnt[m + 1];
        memcpy(cccnt, ccnt, sizeof(ccnt));
        bool del = 0;
        int delnum;
        for (int j = i; j < n; j++)
        {
            if (del)
            {
                cnt[a[j]]--;
                cccnt[a[j]]--;
                if (cccnt[delnum] == 1)
                    del = 0;
                continue;
            }
            if (cccnt[a[j]] > 1)
            {
                del = 1;
                delnum = a[j];
            }
        }
        ccnt[a[i]]--;
    }
    for (int i = 1; i <= m; i++)
        cout << cnt[i] << ' ';
    return 0;
}
