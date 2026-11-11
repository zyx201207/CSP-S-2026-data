#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=n-2;i>=n-m;i--)
	{
		ans=ans&a[i];
	}	
	cout<<ans;
	return 0;
}
