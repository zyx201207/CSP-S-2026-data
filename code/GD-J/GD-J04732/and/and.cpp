#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	
	for(int i=1;i<=m;i++) 
	{
		a[1]=a[1]&a[i];
	}
	cout<<a[1];
	return 0;
}
