#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long ans=0;
	for(int i=1,j=n;i<j;)
	{
		if(b[i]==b[j]&&a[i]==a[j])
		{
			i++,j--;
		}
		else if(b[i]==b[j]&&a[i]<a[j])
		{
			a[j]-=a[i];
			i++;
		}
		else if(b[i]==b[j]&&a[j]<a[i])
		{
			a[i]-=a[j];
			j--;
		}
		else if(b[i]!=b[j]&&a[i]==a[j])
		{
			ans+=a[i];
			i++,j--;
		}
		else if(b[i]!=b[j]&&a[i]<a[j])
		{
			a[j]-=a[i];
			ans+=a[i];
			i++;
		}
		else if(b[i]!=b[j]&&a[i]>a[j])
		{
			a[i]-=a[j];
			ans+=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}
