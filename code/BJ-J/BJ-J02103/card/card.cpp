#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500010],b[300010] = {0},c[500010] = {0};
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++)
    {
        //cout << i << endl;
        int p = 1;
        b[a[i]] = 1;
        int k = n;
        while(a[k] != a[i])
        {
            k--;
        }
        //cout << k << endl;
        if (k == n)
        {
            c[a[i]]++;
            b[a[i]] = 0;
            continue;
        }
        for (int j = k + 1;j <= n;j++)
        {
            //cout << "111\n";
            if (b[a[j]] == 0)
            {
                b[a[j]] = p + 1;
                p++;
            }
            else{
                for (int q = 1;q <= m;q++)
                {
                    if (b[q] > b[a[j]])
                    {
                        p--;
                        b[q] = 0;
                    }
                }
            }
        }
        for (int q = 1;q <= m;q++)
        {
            //cout << "222\n";
            if (b[q] != 0)
            {
                b[q] = 0;
                c[q]++;
            }
        }
    }
    for (int i = 1;i <= m;i++) cout << c[i] << " ";
    return 0;
}
