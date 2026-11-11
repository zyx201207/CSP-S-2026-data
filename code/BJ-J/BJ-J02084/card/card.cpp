#include<bits/stdc++.h>
using namespace std;
long long x[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        for(int j=1;j<i;j++)
        {
            if(x[j]==x[i])
            {
                for(int k=j;k<i;k++)
                {
                    x[k]=0;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[j]==i)
            {
                x[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<x[i]<<" ";
    }
    return 0;
}
