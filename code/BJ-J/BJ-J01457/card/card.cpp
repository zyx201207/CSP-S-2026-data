#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200002],s[100001],sum[1000001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
  }
  for(int i=1;i<=m;i++)
  {
 	  sum[i]=sum[i-1]+s[i];
	  cout<<sum[i]<<" ";
  }
	return 0;
}