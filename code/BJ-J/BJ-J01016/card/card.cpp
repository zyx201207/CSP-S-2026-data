#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],c[500001],tot[500001],tot1[500001];
int main()
{
    int n,m,cnt=1;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)c[i]=a[i];
    for(int i=1;i<=n;i++)
    {
        a[i]=c[i];
        cnt=1;
        memset(b,0,sizeof(b));
        memset(tot1,0,sizeof(tot1));
        int flag=0;
        for(int j=i;j<=n;j++)
        {
            bool flag=true;
            for(int k=1;k<=cnt;k++)
            {
                if(b[k]==a[j])
                {
                    for(int l=k;l<=cnt;l++)
                    {
                        b[l]=0;
                        cnt--;
                    }
                    flag=false;
                    b[cnt]=a[j];

                }
            }
                b[cnt]=a[j];
                cnt++;
        }
        if(b[cnt]==0)
        {
            b[cnt]=0;
            cnt--;
        }
        for(int j=1;j<=cnt;j++)
        {
            tot1[b[j]]++;
        }
        for(int j=1;j<=m;j++)
        {
            if(tot1[j]>1)
            {
                for(int k=1;k<=cnt;k++)
                {
                    if(b[k]==j)
                    {
                        b[k]=0;
                        break;
                    }
                }
            }
        }
        for(int k=1;k<=m;k++)
        {
            for(int j=1;j<=cnt;j++)
            {
                if(b[j]==k)
                {
                    tot[k]++;
                    continue;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<tot[i]<<" ";
}
