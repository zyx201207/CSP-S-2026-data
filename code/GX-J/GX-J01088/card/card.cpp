#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int x;
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=j;k>=i;k--)
            {
                if(a[j]!=a[k])
                {
                    x=1;
                }
                else{
                    x=0;
                }
            }
            if(x==1)
            {
                b[i]=a[i];
            }
            else
            {
                b[i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=0)
        {
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
