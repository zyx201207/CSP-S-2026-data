#include <bits/stdc++.h>
using namespace std;
long long n;
int a[200010];
char c[200010];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	int l=1;
	int r=n;
	while(l<r)
	{
		if(l>=r)
		{
			break;
		}
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r--];
			}
			else if(a[l]==a[r])
			{
				a[l++]-=a[r--];
			}
			else
			{
				a[r]-=a[l++];
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				l++;
				r--;
			}
			else
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
