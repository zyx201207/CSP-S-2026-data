#include <bits/stdc++.h>
using namespace std;

int a[5005],b[5005],d[3005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        int cnt=0;
        for (int j=1;j<=5005;j++) b[i]=0;
        for (int j=i;j<=n;j++)
        {
            d[a[j]]++;
        }
        for (int j=1;j<=m;j++)
        {
            if (d[j]>i)
            {
                int e;
                for (int k=1;k<=n;k++)
                {
                    if (a[k]==j)
                    {
                        e=k;
                        break;
                    }
                }
                for (int k=e;k<=n;k++)
                {
                    d[a[k]]--;
                }
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}
