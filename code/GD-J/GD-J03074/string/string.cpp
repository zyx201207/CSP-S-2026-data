#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n,a[maxn];
char c[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,ans=0;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
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
			else if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
