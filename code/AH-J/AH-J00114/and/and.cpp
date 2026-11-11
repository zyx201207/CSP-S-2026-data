#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 

  int n,m;
  cin>>n>>m;
  int ans = 0;
  for(int i  = 1 ; i <= n ;i++)
  {
  	cin>>a[i]; 
   } 
   sort(a+1,a+1+n);
   
  if(m==1)
  {
  	cout<<a[n];
  }
  if(m==2)
  {
  	 for(int  i = 1 ; i <= n ; i++)
  {
  	for(int j = i+1 ; j <= n ;j++)
  	{
  		ans = max(ans,(a[i]&a[j]));
	  }
  }
  }
  if(m==n)
  {
  	for(int i  =2; i <= n ;i++)
  	{
  		int ans = a[1];
  		ans = (ans&a[i]);
	  }
  }
 

cout<<ans;
	
	return 0;
 } 
