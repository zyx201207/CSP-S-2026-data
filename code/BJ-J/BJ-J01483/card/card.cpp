#include <bits/stdc++.h>

using namespace std;

int a[5000005];
int num[5000005];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        bool ischa[5000005];
        int shu1=0,shu2=0;
        for(int j=i;j<=n;j++)
        {
            if(shu1!=0&&a[j]==1&&j!=shu1)
            {
                for(int k=shu1;k<j;k++)
                {
                    ischa[k]=1;
                }
            }
            if(shu2!=0&&a[j]==2&&j!=shu2)
            {
                for(int k=shu2;k<j;k++)
                {
                    ischa[k]=1;
                }
            }
            if(a[j]==1)
            {
                shu1=j;
            }
            if(a[j]==2)
            {
                shu2==j;
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(ischa[j]==0)
            {
                num[a[j]]++;
            }
        }
        for(int j=1;j<=500005;j++)
        {
            ischa[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;

}
