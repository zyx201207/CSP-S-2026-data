#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int p=0;
	c[0]= ' ';
	for(int i=1;i<=n;i++)
	{
		cin>>a[++p];
		cin>>c[p];
		if(c[p]==c[p-1])
		{
			a[p-1]+=a[p];
			p--;
			continue;
		}
	}
	n=p;
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
				continue;
			}
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
				continue;
			}
			else
			{
				a[r]-=a[l];
				l++;
				continue;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
				continue;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}


