#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int s[500005];
int d[500005];
int sum;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (d[a[j]] == 0)d[a[j]] = j;
            else
            {
                for (int k=d[a[j]];k<=j;k++)
                    d[a[j]] = 0;
                d[a[j]] = j;
            }
        }
        for (int j=1;j<=m;j++)
            if (d[j] > 0)s[j]++;
    }
    for (int i=1;i<=m;i++)
        cout << s[i] << " ";
    return 0;
}
