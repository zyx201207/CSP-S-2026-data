#include <bits/stdc++.h>
using namespace std;
long long  n,m,a[100005];
long long ans;
int cnt;
int book[100005];
long long  kk;

int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
	}
	for(long long  i=1;i<=n;i++)
	{
		
		for(long long  j=i+1;j<=n;j++)
		{
			kk=a[i];
			for(long long  k=1;k<m;k++)
			{
				kk&=a[j+k];
	
			}
			ans=max(ans,kk);
		}
	}
	cout<<ans;
	return 0;
}

	
