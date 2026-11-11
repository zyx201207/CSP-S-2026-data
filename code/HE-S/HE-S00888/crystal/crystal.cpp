#include<bits/stdc++.h>
using namespace std;
long long a[1000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			ans++;
		}
		for(int j=1;j<=m;j++)
		{
			if(a[i]+j==a[i+1])
			{
				a[i]+=j;
				m-=j;
				if(m==0)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
