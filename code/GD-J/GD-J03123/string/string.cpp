#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char zf[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char s;
		scanf("%lld",&a[i]);
		cin>>s;
		zf[i]=int(s-'0');
	}
	int i=0;
	long long ans=0;
	int j=n-1;
	while(i<j)
	{
		if(zf[i]==zf[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j])
			{
				i++;
				j--;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j])
			{
				ans+=a[j];
				i++;
				j--;
			}
			else
			{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
