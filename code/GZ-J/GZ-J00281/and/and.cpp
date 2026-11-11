//GZ-J00281 qiuyirong
#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;
   int a[2001];
   for(int i=0;i<n;i++)
   {

       cin>>a[i];
   }
   if(m==1)
   {
       int mas=0;
       for(int i=0;i<=n;i++)
       {
           if(a[i]>mas)
           {

               mas=a[i];
           }
       }
       cout<<mas;
   }
   else if(m==n)
   {
       for(int i=0;i<n;i++)
       {
           int aaa=1;
           aaa=and(a[i],aaa);
       }
       cout<<aaa;
   }
   else if(m==2)
   {
       int asdf=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {

               if(and(a[i],a[j]>asdf)
                  {
                      asdf=and(a[i],a[j]);
                  }
           }
       }
   }
    return 0;
}
