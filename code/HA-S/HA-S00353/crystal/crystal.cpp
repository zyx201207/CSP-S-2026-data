#include<bits/stdc++.h>
using namespace std;
int n,s,ans=0;
long long m;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	s=(n-1)/2+1;
	int i=1;
	while(m>=0)
	{
		if(a[s-i]!=a[s])
		{
			m--;
			a[s-i]++;
		}
		else
		{
			i++;
			ans++;
		}
	}
	for(int i=s;i<=n;i++)
	{
		if(a[i]==a[s])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
