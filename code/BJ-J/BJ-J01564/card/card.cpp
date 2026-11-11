#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int ans[1000005]={0};
int tong[1000005]={0};
int main()
{
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
        for(int j=i;j<=n;j++)
        {
            tong[a[j]]++;
            if(tong[a[j]]>1)
            {
                for(int k=j-1;k>=0;k--)
                {
                    if(a[k]==a[j])
                    {
                        tong[a[k]]--;
                        break;
                    }
                    tong[a[k]]--;
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(tong[j]==1)
            ans[j]++;
            tong[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
}