#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<ll>a(200010);
	vector<char>c(200010);
	ll n,ans=0,cha;
	bool f;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			f=1;
		}
		else
		{
			f=0;
		}
		if(a[l]==a[r])
		{
			if(f==0)
			{
				ans+=a[l];
			}
			a[l]=0;
			a[r]=0;
			l++;
			r--;
			continue;
		}
		if(a[l]>a[r])
		{
			if(f==0)
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
			continue;
		}
		else
		{
			if(f==0)
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
