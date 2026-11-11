#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10001],ans=1,sum;
int main()
{
	freopen("and5.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
		for(int i=n;i>=n-m+1;i--)
		{
			ans=ans&a[i];
		}
	cout<<ans;
	return 0;
}
