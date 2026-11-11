#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],sum;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]==a[r])
			{
				sum+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else
			{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
