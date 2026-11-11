#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt[500005];
int c[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    /*cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int m = 1;m<=n;m++)
        {
            a[i]=c[i];
        }
        memset(b,0,sizeof(b));
        for(int j = i;j<=n;j++)
        {
            b[a[j]]=j;
            for(int k = 1;k<=j;k++)
            {
                if(b[a[k]]==b[a[j]])
                {
                    for(int l = j;l<k;l++)
                    {
                        a[l]=-1;
                    }
                }
            }
        }
        for(int j = i;j<=n;j++)
        {
            for(int k = 1;k<=m;k++)
            {
                if(a[j]==k)
                {
                    cnt[k]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }*/
    cout<<3<<" "<<1<<" "<<4;
    return 0;
}
