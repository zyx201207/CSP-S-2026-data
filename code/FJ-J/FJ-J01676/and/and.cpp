#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxx=a[n];
	for(long long i=n-1;i>=n-m+1;i--)
	{
		maxx&=a[i];
	}
	cout<<maxx;
	return 0;
 } 
