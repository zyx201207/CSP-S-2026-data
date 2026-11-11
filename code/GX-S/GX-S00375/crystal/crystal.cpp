#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int MAXX=500000+20;
int n;
long long m,a[MAXX],f[MAXX],v[MAXX],cnt;
bool cmp(long long a,long long b)
{
	return a<b;
}

long long dj(int x,int y)
{
	return v[y]-(v[x-1]+(a[y]-a[x-1])*(x-1));
}
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(long long i=1;i<=n;i++)
  {
	 // cin>>a[i];
	 a[i]=i;
  }
  sort(a+1,a+n+1,cmp);
  for(int i=2;i<=n;i++){f[i]=a[i]-a[i-1];v[i]=v[i-1]+(i-1)*f[i];}
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";
  cout<<endl;
  int l=1,r=n;
  while(dj(l,r)>m && l<r)
  {
	//  cout<<" djl+1:"<<dj(l+1,r)<<" djr-1:"<<dj(l,r-1)<<endl;
	  if(f[l+1]>f[r])
	//  if(dj(l+1,r)<dj(l,r-1))
	  {
		  l++;
	  }
	  else
	  {
		  r--;
	  }
	  cout<<"end:l"<<a[l]<<" r"<<a[r]<<endl;
  }
  if(l==r)cout<<1;
  else cout<<r-l+1;
  return 0;
}
