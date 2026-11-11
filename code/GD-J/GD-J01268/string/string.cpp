#include <bits/stdc++.h>
using namespace std;
int n,a[300005],l,r;
long long num=0;
char c[300005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<=r)
	{
		if(c[l]==c[r])
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
				num+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r])
			{
				num+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				num+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<num;
	
	return 0;
} 
