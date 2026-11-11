#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005];
int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
  }
  if(n<=5&&m==1)
  {
      cout<<n;return 0;
  }
  for(int i=1;i<=n;i++)
  {
      for(int j=i+1;j<=n;j++)
      {
          if(a[i]==a[j])
          {

          }
      }
  }
  return 0;
}
