#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int main ()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            b[j]=a[j];
            for(int r=1;r<j;r++)
            {
                if(b[r]==b[j])
                {
                    for(int l=1;l<j;l++)
                    {
                        b[l]=0;
                    }
                }
            }
        }


        for(int h=1;h<=n;h++)
        {
            if(b[h]!=0)
            {
                c[b[h]]++;

            }
        }
        for(int t=1;t<=n;t++)
        {
            b[t]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(c[i]!=0)
        {
            printf("%d",c[i]);
            cout<<" ";
        }
    }


    return 0;
}
