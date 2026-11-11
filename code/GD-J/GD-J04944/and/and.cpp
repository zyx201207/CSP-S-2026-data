#include<bits/stdc++.h>
using namespace std;
long long int a[1010101];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n,m;
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long int ans=a[n-1];
	for(long long int i=n-1;i>=n-m+1;i--)
	{
		ans&=a[i];
	}
	cout<<ans;
}
