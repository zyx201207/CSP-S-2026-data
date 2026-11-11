#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005],cards[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x=1;
        for(int j=i;j<=n;j++)
        {
            cards[x++]=a[j];
            for(int k=x-2;k>0;k--)
            {
                if(cards[k]==cards[x-1])
                {
                    for(int l=k+1;cards[l]!=0;l++)
                    {
                        cards[l]=0;
                    }
                    x=k+1;
                    break;
                }
            }
        }
        for(int j=1;cards[j]!=0;j++)
        {
            sum[cards[j]]++;
            cards[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<sum[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
