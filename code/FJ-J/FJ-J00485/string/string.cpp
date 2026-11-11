#include <bits/stdc++.h>
using namespace std;
int t;
long long num[200002];
char a[200002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>num[i]>>a[i];
	}
	long long ans=0;
	int l=1,r=t;
	while (l<r)
	{
		if (a[l]!=a[r])
		{
			if(num[l]>num[r])
			{
				num[l]-=num[r];
				ans+=num[r];
				r--;
			}
			else if (num[r]>num[l])
			{
				num[r]-=num[l];
				ans+=num[l];
				l++;
			}
			else
			{
				ans+=num[l];
				l++;
				r--;
			}
		}
		else
		{
			if (num[l]>num[r])
			{
				num[l]-=num[r];
				r--;
			}
			else if(num[r]>=num[l])
			{
				num[r]-=num[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}