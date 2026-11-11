#include<bits/stdc++.h>
using namespace std;
int n,z;
long long m,a[500001],cz[500001],ans=0,k=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	z=(n+1)/2;
	k=z;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[z]==a[i])
		{
			ans++;
		}
	}
	k--;
	for(int i=1;i<=m+1;i++)
	{
		if(a[k]==a[z])
		{
			k--;
			ans++;
			i--;
			continue;
		}
		a[k]++;
	}
	cout<<ans;
	return 0;
} 
