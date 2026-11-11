#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  cin>>n>>m; 
  for(int i=1;i<=n;i++) 
    cin>>a[i];
  sort(a+1,a+1+n);
  if(m==1)
  {
    cout<<a[n];
    return 0;
  }
  else if(m==n)
  {
  	int b=1;
  	for(int i=1;i<=n;i++)
  	{
  	  b=b&a[i]; 
	}
	cout<<b;
	return 0;
  }
  else
  {
  	int c=-917813;
  	do
  	{
  	  int b=a[1];
  	  for(int i=1;i<=m;i++)
  	  	b=b&a[i];
  	  c=max(c,b); 
    }
    while(next_permutation(a+1,a+1+n));
    cout<<c;
    return 0;
  }
  return 0;
}
