#include<bits/stdc++.h>
using namespace std;
int best=0,n,m;
long long a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>n-m;i--)
	{
		a[i]=a[i]&a[i+1];
		best=a[i];
	}
	cout<<best;
	return 0;
 } 
