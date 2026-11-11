#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200001],n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n=1)
	{
		sort(a,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(n==m)
	{
		int cnt=a[1];
		for(int i=1;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(n=2)
	{
		int maxx=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			if(a[i]&a[j]>maxx)
			{
				maxx=a[j]&a[i];
			}
		}
		cout<<maxx;
		return 0;
	}
	if(a[2]==1)
	{
		cout<<n-2;
		return 0;
	}
	sort(a,a+n+1);
	cout<<a[m-n+1];
	return 0;
}
