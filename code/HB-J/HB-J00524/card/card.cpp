#include <bits/stdc++.h>
using namespace std;
int tab[5005],card[5005],cnt[3005],xb;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> card[i];
    for(int i=1;i<=n;i++)
    {
        xb=0;
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=xb;k++)
            {
                if(tab[k]==card[j])
                {
                    xb=k-1;
                    break;
                }
            }
            xb++;
            tab[xb]=card[j];
        }
        for(int j=1;j<=xb;j++)
        {
            cnt[tab[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
//O(n^3/4) ~ O(n^2)
