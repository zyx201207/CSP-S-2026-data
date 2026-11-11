#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a=0;
    long long z[10000];
    long long b[10000];
    for(int i=0;i<n;i++)
    {
        cin>>z[i];
    }
    int min=0;
     sort(z,z+n-1);
     for(int j=n-1;j>=0;j--)
     {
        for(int i=j-1;i>=0;i--)
     {
          a+=z[j]-z[i];
         if(a<=m)
         {
             min++;
             b[j]=min;
         }
         else
            min=0;
         break;

     }
     }
      int count=b[n-1];;
     for(int j=n-1;j>=0;j--)
     {
         if(b[j-1]>b[j])
         {
             count=b[j-1];
         }
     }
     cout<<count+1;
    return 0;
}
