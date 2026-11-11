#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;  
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i+1]&&a[i+1]<a[i++])
		{
			a[i]++;
		}
		if(a[i+1]<a[i]&&a[i+1]<a[i++])
		{
			a[i+1]++;
		}
		if(a[i]=a[i+1])
		{
			ans++;	
		}
	}
	cout<<ans;
	
	
	return 0;
}
