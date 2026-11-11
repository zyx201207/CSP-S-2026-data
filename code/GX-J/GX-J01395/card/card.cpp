#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],aa[200001],ans[200001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];aa[i]=a[i];}
    for(int i=1;i<=n;i++)
    {
        for(int y=1;y<=n;y++)
        {
            a[y]=aa[y];
        }
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                if(a[k]==a[j]&&j!=k)
                {
                    for(int ii=k;ii<=j;ii++)
                    {
                        a[ii]=-1;
                    }
                }
            }
        }
        for(int y=1;y<=n;y++)
        {
            if(a[y]!=-1)
            {
                ans[a[y]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
