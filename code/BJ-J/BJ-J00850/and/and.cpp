#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],bin[200005][30],num,ans=0;
bool f[200005],past[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=29;j++)
        {
            bin[i][j]=a[i]%2;
            a[i]/=2;
        }
    }
    for(int i=29;i>=0;i--)
    {
        num=0;
        for(int j=1;j<=n;j++)
        {
            if(bin[j][i]==1)
            {
                num++;
                f[j]=1;
            }
        }
        if(num<m)
        {
            for(int j=1;j<=n;j++)
            {
                f[j]=0;
            }
        }
        else
        {
            ans+=pow(2,i);
            for(int j=i-1;j>=0;j--)
            {
                num=0;
                for(int k=1;k<=n;k++)
                {
                    past[k]=f[k];
                    if(bin[k][j]==1&&past[k]==1)
                    {
                        num++;
                        f[k]=1;
                    }
                    else
                    {
                        f[k]=0;
                    }
                }
                if(num<m)
                {
                    for(int k=1;k<=n;k++)
                    {
                        f[k]=past[k];
                    }
                }
                else
                {
                    ans+=pow(2,j);
                }
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}
