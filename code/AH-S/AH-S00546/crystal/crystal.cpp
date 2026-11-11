#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N],b[N],s[N];
int maxn=INT_MIN;
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  scanf("%lld %lld",&n,&m);
  for(int i=1;i<=n;i++) scanf("%lld",a+i);
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++) 
   {
	  s[i]=s[i-1]+a[i];
	  b[i]=a[i]*(i-1)-s[i-1];
   }
  for(int i=1;i<=n;i++)
  {
	int l=1,r=i;
    while(l<r)
    {	
	  int mid=(l+r)/2;
	  ll tmp=b[i]-((mid-1)*a[i]-s[mid-1]);
	  if(tmp>m) l=mid+1;
	  else r=mid;
    }
    maxn=max(maxn,i-r+1);
  }
  printf("%d",maxn);
  return 0; 
}
