#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=1;i<=m;i++)
	{
		ans=ans&a[n-i];
	}
	cout<<ans;
}
