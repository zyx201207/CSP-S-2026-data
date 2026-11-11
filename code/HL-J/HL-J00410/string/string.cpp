#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,ans;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	int i=1,z=10;
	while(sum>1)
	{
		if(a[i]>a[n]&&b[i]!=b[n])
		{
			ans+=a[n];
			a[i]-=a[n];
			sum-=2*a[n];
			n--;
		}
		else if(a[i]==a[n]&&b[i]!=b[n])
		{
			ans+=a[n];
			sum-=2*a[n];
			n--;
			i++;
		}
		else if(a[i]<a[n]&&b[i]!=b[n])
		{
			ans+=a[i];
			a[n]-=a[i];
			sum-=2*a[i];
			i++;
		}
		else if(a[i]>a[n])
		{
			a[i]-=a[n];
			sum-=2*a[n];
			n--;
		}
		else if(a[i]==a[n])
		{
			sum-=2*a[n];
			n--;
			i++;
		}
		else if(a[i]<a[n])
		{
			a[n]-=a[i];
			sum-=2*a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
