#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l=1,r;
char c[200005];
long long sum;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(r>l)
	{
		if(c[l]!=c[r])
		{
			sum+=min(a[l],a[r]);
			if(a[l]<a[r])
			{
				a[r]=a[r]-a[l];
				l++;
			}
			else if(a[l]>a[r])
			{
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				r--;
				l++;
			}
		}
		else if(c[l]==c[r])
		{
			if(a[l]<a[r])
			{
				a[r]=a[r]-a[l];
				l++;
			}
			else if(a[l]>a[r])
			{
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				r--;
				l++;
			}
		}
	}
	cout<<sum;
	
	return 0;
}
