#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char c[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]==a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
			}
			l++;
			r--;
		}
		if(a[l]<a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
