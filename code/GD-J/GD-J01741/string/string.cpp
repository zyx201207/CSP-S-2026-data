#include<bits/stdc++.h>
using namespace std;
int n,a[200003];
long long ans;
char b[200003];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(b[l]==b[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else 
			{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else 
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]==a[r])
			{
				l++;
				ans+=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
