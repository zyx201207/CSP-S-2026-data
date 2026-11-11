#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],b[300005],d[500005],e[500005];
    bool c[500005];
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int h = n;
    while(n--)
    {
        int l = 1,j = 1;
        bool flag = true;
        for(int i = h - n;i <= h;i++)
        {
            e[l] = a[i];
            l++;
        }
        l--;
        int g = l;
        c[500005] = {0};
        while(l--)
        {
            if(c[e[j]])
            {
                d[500005] = {0};
                d[1] = e[j];
                for(int i = 1;i <= g - n;i++)
                {
                    e[i] = e[++j];
                }
                j = 1;
            }
            else
            {
                d[j] = e[j];
                c[e[j]] = true;
            }
            if(l == 0)
                for(int i = 1;i <= m;i++)
                    for(int k = 1;k <= j;k++)
                        b[i] += (d[k] == i);
            j++;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
