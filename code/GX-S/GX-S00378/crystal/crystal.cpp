#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long a[1000];
long long n,m;
cin>>n>>m;
long long cs=0,sum=0,ans=3;
for(long long i=1;i<=n;i++)
{
cin>>a[i];
for(long long i=1;i<=n;i++)
 {

     if(a[i]+1==a[i+1])
     {   cs++;
         sum++;
         break;

     }
     else{
         if(a[i]+2==a[i+1])
         {
             cs++;
             sum++;
             break;
         }
         else{
            if(a[i]+1!=a[i+1])
     {
         if(a[i]==a[i+1])
         {
             cs++;
             sum++;
             break;
         }
         else
            {
                break;
            }
         }
     }
     }

 }
}
for(long long i=1;i<=1;i++)
 if(cs<=m&&sum>=ans&&a[i]>0)
 {

    cout<<sum-1;
 }
 else{cout<<sum;}
return 0;
}
