#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int cmp=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	if(n==1)
	  cout<<a[1];
	else
	{
		for(int i=1;i<=n;i++)
	   {
	  	    cmp=max(a[i],cmp);
	   }
	  cout<<cmp;
	}
}