#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[300005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int sz[300005];
    int desk[300005];
    int ans[300005];
    for(int i=1;i<=n;i++)
    {
        int ii=1;
        for(int i=1;i<=300005;i++)
        {
            sz[i]=0;
        }
        int head=1;
        int tail=0;
        for(int j=i;j<=n;j++)
        {
            if(sz[j]==0)
            {
                sz[j]=1;
                tail++;
                desk[tail]=j;
            }
            else
            {
                int aaa=0;
                for(int k=tail;k>=head;k--)
                {
                    if(desk[k]==j)
                    {
                        aaa=k;
                    }
                }
                head=aaa;
                tail=head;
                desk[tail]=j;
            }
        }
        while(ii<=m)
        {
            for(int j=0;j<=tail;j++)
            {
                if(desk[j]==ii)
                {
                    ans[ii]++;
                }
            }
            ii++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
