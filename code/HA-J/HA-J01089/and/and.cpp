#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
int n,m,a[N];
int zd,he;
bool b;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==1)
	{
	  for(int i=1;i<=n;i++)
	  {
	  	if(a[i]>zd) zd=a[i];
	  }
	  cout<<zd;
	  return 0;
	}
	if(m==n)
	{he=a[1];
      for(int i=2;i<=n;i++)
      he=he|a[i];
      cout<<he;
      return 0;
	}
	for(int i=1;i<=n;i++)
	{
	  if(a[i]|0!=0) b=1;
	}
	if(b==0) 
	{ sort(a+1,a+n+1,cmp);
	  int dou=a[1];
	  for(int i=2;i<=m;i++)
	  dou=dou|a[i];
	  cout<<dou;
	  return 0;
	}
	int f;
	for(int i=1;i<=n;i++)
	{for(int j=1;j<=n;j++)
	 {for(int x=1;x<=n;x++)
	  f=a[i]|a[j]|a[x];
	  int da=-100;
	  if(da<f) da=f;
	 }
	}
	cout<<f;
	return 0;
}
