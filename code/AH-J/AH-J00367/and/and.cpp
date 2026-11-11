#include <iostream>
#include <cstring>

using namespace std;

const int N=2*1e5+10;
int n,m;
unsigned long long a[N],f[2100][2100];

int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
  
  unsigned long long maxn=-1;
  for(int i=1;i<=n;i++)maxn=max(a[i],maxn);
  
  if(m==1)return cout<<maxn,0;
  
  if(m==n)
  {
	  int ans=1;
	  for(int i=1;i<=n;i++)ans=ans&a[i];
	  
	  return cout<<ans,0;
  }
  
  if(m==2)
  {
	  unsigned long long t=-1;
	  for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(i!=j)t=max(t,a[i]&a[j]);
		
	  return cout<<t,0;
  }
  
  return 0;
}
