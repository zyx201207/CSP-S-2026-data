#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[200005],b[200005],s[200005];
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[a[i]]++;
        s[i] = 0;
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = i;j <= n;j++)
        {
            s[a[j]]++;
            if (b[a[j]] > 1)
            {
                for (int k = j + 1;k <= n;k++)
                {
                    if (a[k] == a[j])
                    {
                        j = k;
                        break;
                    }
                }
            }
        }
        b[a[i]]--;
    }
    for (int i = 1;i <= m;i++) cout << s[i] << " ";
}
