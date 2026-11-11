#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i = 1;i<=n/2;i++)
	{
		if(a[i]>a[n-i+1])
		{
			for(int j = n;j>=n-a[i];j-=a[j])
			{
				if(c[i]==c[j])
				{
					ans-=a[j];
				}
			}
			ans+=a[i];
		}
		else
		{
			for(int j = 1;j<=a[n-i+1];j+=a[j])
			{
				if(c[i]==c[n-i+1])
				{
					ans-=a[n-i+1];
				}
			}
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}
