#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum=a[n];
	for(int i=n;i>=n-m;i++)
	{
		sum=(sum & a[i-1]);
		cout<<sum<<" ";
	}
	cout<<sum;
	return 0;
 } 
