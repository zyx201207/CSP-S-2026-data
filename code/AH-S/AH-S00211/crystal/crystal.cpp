#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=5*1e5+10;
long long n,m;
long long a[N],s[N];

int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  
  scanf("%lld %lld",&n,&m);
  for(int i=1;i<=n;i++)scanf(" %lld",&a[i]);
  for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
  
  sort(a+1,a+1+n);
  
  long long i=1,j=1,maxn=-2;
  while(i<=j&&j<=n)
  {
	  if(s[j]-s[i-1]+m>=a[j+1]*(j-i+1))j++,maxn=max(maxn,j-i+1);
	  if(s[j]-s[i-1]+m<a[j+1]*(j-i+1))i++,maxn=max(maxn,j-i+1);
  }
  
  printf("%lld",maxn);
  return 0;
}
