#include<bits/stdc++.h>
using namespace std;
long long n,m,a[int(2e5+7)],s=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n-m+1;i<n;i++)
	{
		s&=a[i];
	}
	cout<<s;
	return 0;
}
