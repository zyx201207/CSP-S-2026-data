#include <bits/stdc++.h>
using namespace std;
int m,n;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    int mmm[m+1][2]={0};
    int a[n+5]={0};
    int my[m+1]={0};
    bool f[n+5];
    int x[m+2][n+2]={0};
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        for(int i=1;i<=m;i++)
        {
            x[m][i]=x[m][i-1];
        }
        x[a[i]][i]++;

        my[a[i]]=i;
    }
    int t=n-1;
    while(t--)
    {
        for(int i=1;i<=m;i++)
        {

            mmm[i][1]=0;
        }
        int mx[m+1]={0};
        for(int i=1;i<=n;i++)
        {
            f[i]=1;
        }
        int k=n-t;
        for(int i=1;i<k;i++)
        {
            f[i]=0;
        }
        for(int i=k;i<=n;i++)
        {
            if(f==0)
            {
                continue;
            }
            for(int j=1;j<=m;j++)
            {
                if(x[a[i]][i]!=x[a[i]][i-1])
                {
                    if(mx[a[i]]==0)
                    {
                        mx[a[i]]=i;
                    }
                    else
                    {
                        for(int s=mx[a[i]];s<my[a[i]];s++)
                        {
                            f[s]=0;
                        }

                    }

                }
            }
        }
        for(int i=k;i<=n;i++)
        {
            if(f[i]==1&&mmm[a[i]][1]==0)
            {
                mmm[a[i]][0]++;
                mmm[a[i]][1]=1;
            }
        }


    }
    for(int i=1;i<=m;i++)
    {

        cout << mmm[i][0] << ' ';
    }

    return 0;


}


