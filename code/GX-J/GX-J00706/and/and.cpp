#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[1001],b[10001],c[1001];
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
	  cin>>a[i];
  }
  cout<<a[n];
  return 0;
}

