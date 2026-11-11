#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long num[1000010];//最多拼接的数量 
long long w[1000010];//总共需要的操作次数 
long long n,m;
long long ans;  
long long temp=1;
int main()
{
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
 ios::sync_with_stdio(false);
 cin.tie(0);
 cin>>n>>m;;
 for(long long i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 sort(a+1,a+n+1);
 num[1]=1;
 w[1]=0;
 for(long long i=2;i<=n;i++)
 {
  w[i]=w[i-1]+num[i-1]*(a[i]-a[i-1]);
  num[i]=num[i-1]+1;

   while(w[i]>m)
   {
    w[i]=w[i]-(a[i]-a[temp]);
    temp++;
    num[i]--;
   }
   ans=max(ans,num[i]);
 }
 cout<<ans;
 return 0;
} 
