#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
long long a[200010]={0};
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
	s=a[n-1];
	for(int i=n-1;i>=m;i--)
	{
		s&=a[i];
	}
	cout<<s;
	return 0;
} 
