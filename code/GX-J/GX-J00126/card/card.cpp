#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,l=0;
    cin>>n>>m;
    int card[n],num[n][n],y=0,i=0,a=0;

    for (int i=0;i<n;i++) for (int j=i;j<n;j++) num[i][j]=1;


    for (int i=0;i<n;i++) cin>>card[i];

    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            for (int k=1;k<n;k++)
            {
                if (card[j]==card[k])
                {
                    if (num[i][j] == num [i][k])
                    {
                        for (int l=j;l<k;l++)
                        {
                            num[i][l]=0;
                        }
                    }
                }
            }
        }
    }
    int sum[m+1],black[m];
    for (int i=0;i<m+1;i++)
    {
        sum[i]=0;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (num[i][j]==1)
            {
                int k=0;
                k=card[j];
                sum[k]=sum[k]+1;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<sum[i]<<" ";
    }

    return 0;
}

