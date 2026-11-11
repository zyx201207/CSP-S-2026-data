#include<bits/stdc++.h>

using namespace std;

int n,m,a[500005],b[300005],c[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int j = 1;j<=n;j++)
    {
        cin>>a[j];
    }
    while(m--)
    {
        for(int i = 1;i<=n;i++)
        {
            c[i] = a[i];
            for(int j = 1;j<=i;j++)
            {
                if(c[j] == c[i])
                {
                    for(int k = j;k<i;k++)
                    {
                        c[k] = 0;
                    }
                }
            }
        }
        for(int i = 1;i<=n;i++)
        {
            if(c[i] != 0)b[c[i]]++;
            c[i] = 0;
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
