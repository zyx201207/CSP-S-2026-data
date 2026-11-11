#include<bits/stdc++.h>

using namespace std;

long long n,a[200010],C;
string s[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		if(s[l]==s[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				a[r]=0;
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
				C+=a[r];
				a[r]=0;
				r--;
			}
			else 
			{
				a[r]-=a[l];
				C+=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<C;
	return 0;
}
