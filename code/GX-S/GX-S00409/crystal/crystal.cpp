#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int n,m,c=0,d=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               for(int z=0;z<=m;z++)
               {

                   if(a[j]+z==a[i]&&i!=j)
                   {
                       a[j]=a[j]+z;
                       m=m-z;
                       c++;
                   }
               }
               if(c>d)
                   {
                       d=c;
                   }
           }
       }
       cout<<d<<endl;
       return 0;
}
