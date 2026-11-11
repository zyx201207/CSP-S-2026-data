#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[1000010];
int main()
{
 freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
 ios::sync_with_stdio(false);
 cin.tie(0);
 cin>>c>>t;
 for(long long ii=1;ii<=t;ii++)
 {
  memset(a,0,sizeof(a));
  cin>>n>>d;
  for(long long i=1;i<=n;i++)
  {
   cin>>a[i];
  }
  d=d/(a[n]-a[n-1]);
  if(d==0||d==1)
  {
   cout<<"0"<<endl;
  }
  else if(n>=2*d-1)
  {
    cout<<n-2*d+1<<endl;
  }
  else
  {
   cout<<"0"<<endl;
  }
 }  
 return 0;
}
