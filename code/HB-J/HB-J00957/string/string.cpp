#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   string ans;
   long long n,sum=0,l=0,f,w=1,a,j=0;
   char b;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
     cin>>a>>b;
     l+=a;
     j+=a;
     for(int i=w;i<=j;i++)
     {
         ans[i]=b;
     }
     w=w+2;
   }
   if(l%2==0)
    f=l/2+1;
   else
    f=l/2+2;
   for(int i=l/2;i>=1;i--)
   {
       if(ans[f]!=ans[i])
       sum++;
       f++;
   }
   cout<<sum;
   return 0;
}
