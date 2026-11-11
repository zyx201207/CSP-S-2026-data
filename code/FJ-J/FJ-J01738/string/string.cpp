#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200100];
char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1])
		{
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else
			{
				a[l]-=a[r];
				r--;
			}
		}
		else
		{
			if(a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
