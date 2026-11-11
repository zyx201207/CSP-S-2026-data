#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,a[200001],m;
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  sort(a+1,a+n+1);
  if(m==1)
  {
	cout<<a[n];
	return 0;  
  }
  int aa=a[n-m+1];
  for(int i=n-m;i>=n-1;i++)
  {
	aa=aa && a[i+1];
  } 
  cout<<aa<<" ";
  return 0;
}
