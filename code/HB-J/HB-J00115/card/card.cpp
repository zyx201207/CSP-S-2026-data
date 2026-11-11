#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long card[n+5],cnt[m+1];
    for(int i=1;i<=n;i++)
    {
        cin >> card[i];
    }
    int ls[n+5]={0},ls2[n+5]={0},long0=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n-i+1;j++)
        {
            ls[j] = card[j+i-1];
            for(int a=1;a<j;a++)
            {
                if(ls[j]==ls[a])
                {
                    for(int b=1;b<=a;b++)
                    {
                        ls2[b] = ls[b];
                    }
                    ls[n+5]={0};
                    for(int b=1;b<=a;b++)
                    {
                        ls[b] = ls2[b];
                    }
                    ls2[n+5]={0};
                    long0=a;
                    j=a;
                    break;
                }
            }
            for(int c=1;c<=m;c++)
            {
                for(int d=1;d<=long0;d++)
                {
                    if(ls[d]==c)
                    {
                        cnt[c]++;
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}
