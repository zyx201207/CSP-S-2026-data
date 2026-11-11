#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k=a[i],f=0,t=0;
        for(int j=1;j<=i-1;j++)
        {
            if(b[j]!=k)
            {
                f=1;
            }
            else
            {
                t=i;
            }
        }
        if(f==1)
        {
            b[i]=k;
        }
        else
        {
            for(int i=1;i<=t;i++)
            {
                b[i]=0;
            }
        }
        if(b[i]!=0)cout<<b[i]<<" ";
    }
    return 0;
}
