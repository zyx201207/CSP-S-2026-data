#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],num[300005],ans[500005],cnt[300005],lol[300005];
bool flag = true;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) flag = false;
        sum[a[i]] = i;
    }
    if(flag)
    {
        for (int i = 1;i <= n;i++)
        {
            if(sum[a[i]] == i) num[a[i]] += i;
        }
        for (int i = 1;i <= m;i++) cout << num[i] << " ";
        return 0;
    }
    else
    {
        for (int i = 1;i <= n;i++)
        {
            int p = 1;
            for (int k = 1;k <= m;k++)
            {
                cnt[k] = 0;
                lol[k] = false;
            }
            for (int j = i;j <= n;j++)
            {
                if (cnt[a[j]] == 0)
                {
                    ans[p] = a[j];
                    p++;
                    cnt[a[j]] = j;
                }
                else
                {
                    p = cnt[a[j]] + 1;
                    for (int l = p;l <= n;l++)
                    {
                        if(cnt[ans[l]] == l) cnt[ans[l]] = 0;
                        ans[l] = 0;
                    }
                }
            }
            for (int i = 1;i < p;i++)
            {
                lol[ans[i]] = true;
            }
            for (int i = 1;i <= m;i++)
            {
                if(lol[i]) num[i]++;
            }
        }
        for (int i = 1;i <= m;i++)
        {
            cout << num[i] << " ";
        }
    }
    return 0;
}
