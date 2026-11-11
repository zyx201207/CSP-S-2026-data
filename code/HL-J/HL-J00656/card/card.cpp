#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], zm[500010], cnt[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[n];
    }
    for(int i = 1; i <= n; i++)
    {
        int bj = i;
        for(int j = i; j <= n; j++)
        {
            bool flag = 0;
            for(int k = 1; k <= n; k++)
            {
                if(a[j] == zm[k])
                {
                    flag = 1;
                    bj = k;
                }
                if(zm[k] == 0)
                {
                    break;
                }
            }
            if(flag == 1)
            {
                while(true)
                {
                    int t = bj+1;
                    if(zm[t] == 0)
                    {
                        break;
                    }
                    zm[t] = 0;
                }
            }
            else
            {
                zm[bj] = a[j];
            }
            bj++;
        }
        for(int j = 1; j <= m; j++)
        {
            cnt[zm[j]]++;
            cout << cnt[zm[j]] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
