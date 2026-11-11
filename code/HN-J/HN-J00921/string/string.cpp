#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char s[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>s[i];
	}
	int ans=0;
	int l=1;
	int r=n;
	while(l<r)
	{
		if(s[l]==s[r])
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				a[l]-=a[r];
				r--;
			}
		}
		else
		{
			if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
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

