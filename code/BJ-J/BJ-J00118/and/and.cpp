#include<bits/stdc++.h>
using namespace std;

int ans=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=1;i<=m-1;i++)
	{
		ans=ans&a[n-i];
	}	
	cout<<ans<<endl;
	return 0;
}
