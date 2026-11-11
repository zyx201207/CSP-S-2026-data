#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long a[n];
     long long b[m]={0};
     for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int z=0;
     for(int k=0;k<n;k++)
     {
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(a[i]==a[j]&&i!=j)
            {
                z=max(z,i);
            }
        }
    }
   for(int i=z;i<n;i++)
   {
       b[a[i]]++;
   }
     }
     for(int i=0;i<m;i++)
     {
         cout << b[i] << " ";
     }
    return 0;
}
