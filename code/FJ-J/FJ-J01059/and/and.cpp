#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n=0,c=0,ans=0; 
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
		for(int i=n-1;i>=n-c+1;i--)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0; 
}
