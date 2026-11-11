#include<bits/stdc++.h>
using namespace std;
long long n,mid,a[200005],ans;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		mid+=a[i];
	}
	long long l=1,r=n,lsum=0,rsum=mid;
	mid/=2;
	bool flag=1;
	while(flag)
	{
		if(l==r)
		{
			break;
		}
		if(a[l]==a[r]&&abs(l-r)==1)
		{
			if(s[l]!=s[r])
			{
				ans+=a[l];
			}
			break;
		}
		if(s[l]==s[r])
		{
			if(a[l]==a[r])
			{
				l++,r--;
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
			ans+=min(a[l],a[r]);
			if(a[l]==a[r])
			{
				l++,r--;
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
	}
	cout<<ans;
	return 0;
}

