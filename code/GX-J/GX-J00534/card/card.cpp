#include<bits/stdc++.h>
using namespace std;
const int N=5600;
int n,m,k,z,c;
int a1[N],a[N],x[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    k=n;
    z=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a1[i]=a[i];
    }
    while(k--)
    {
        int b[N]={};
        c=z;
        for(int i=z;i<=n;i++)
        {
            b[a[i]]++;
            if(b[a[i]]>1)
            {
                c=i;
            }
        }

        for(int i=c;i<=n;i++)
        {
            x[a[i]]++;

        }

        z++;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<x[i]<<" ";
    }
   return 0;
}
