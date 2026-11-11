#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	x=a[n];
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
	 } 
	else
	{
		cout<<x;
	}
	return 0;
 } 
