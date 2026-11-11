#include<bits/stdc++.h>
using namespace std;
long long len;
long long n;
long long ans;
long long a[10000005];
char c[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<j)
	{
		if(c[i]!=c[j])
		{
			if(a[i]!=a[j])
			{
				ans+=min(a[i],a[j]);
				if(a[i]>a[j])
				{
					a[i]-=a[j];
					a[j]=0;
					j--;
				}
				else if(a[i]<a[j])
				{
					a[j]-=a[i];
					a[i]=0;
					i++;
				}
			}
			else if(a[i]==a[j])
			{
				ans+=a[i];
				i++;
				j--;
			}
		}
		else if(c[i]==c[j])
		{
			if(a[i]!=a[j])
			{
				ans+=abs(a[i]-a[j]);
				if(a[i]>a[j])
				{
					a[i]-=a[j];
					a[j]=0;
					j--;
				}
				else if(a[i]<a[j])
				{
					a[j]-=a[i];
					a[i]=0;
					i++;
				}
			}
			else if(a[i]==a[j])
			{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
}
