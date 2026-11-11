#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,c,a[1000086],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=c;i>=1;i--)
	{
		ans=a[i]&a[i-1];
	}
	cout<<ans;
	return 0;
}
