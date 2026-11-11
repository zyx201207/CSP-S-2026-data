#include <bits/stdc++.h>
using namespace std;
int mian ( )
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int zhan[800111] = {};
    int head = 0,tail = 0,ch = 0,ct = 0;
    int n = 0,m = 0;

    cin >> n >> m;

    bool book[m + 1] = {};
    int card[n] = {};

    for (int i = 0;i < n;i++)
    {
        cin >> card[i];
        ct++;
    }

    int i = 1;
    int ans[m+1] = {};
    while (ct != ch)
    {
        int th = i;
        for (int j = th;j <= ct;j++)
        {
            if (book[card[j]] == 1)
            {
                for (int l = head;l <=tail;l++)
                {
                    if (zhan[l] == card[j])
                    {
                        head += l;
                        zhan[tail] = card[j];
                        tail++;
                    }
                }
            }
            else
            {
                zhan[tail] = card[j];
                tail++;
                book[card[j]] = 1;
            }
            for (int j = 1;j <= m;j++)
            {
                if (book[j] == 1)
                {
                    ans[j] += 1;
                }
            }
        }
    }
    for (i = 1; i <= m;i++)
    {
        cout << ans[i];
    }
    return 0;
}
