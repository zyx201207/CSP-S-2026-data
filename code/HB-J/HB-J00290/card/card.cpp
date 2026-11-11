#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int b[n+5],l[n+5];
      for(int i=1;i<=n;i++)
    {
        for(int j=1+i-1;j<=n;j++)
        {
            for(int x=j+1;x<=n;x++)
            {
                if(a[j]=a[x])
                {
                    l[i]=a[j];
                    break;
                }
                else
                {
                    b[i]=a[j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<l[i]<<" ";
    }
}
