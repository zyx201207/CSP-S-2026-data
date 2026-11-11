#include<bits/stdc++.h>
using namespace std;
#define int long long
string a="";
int num[200005];
long long sum=0;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		cin>>c[i];
		a+=c[i];
	}
	bool f=0;
	for(int i=0;i<a.size()/2;i++)
	{
		if(a[i]!=a[a.size()-i-1])
		{
			f=1;
			break;
		}
	}
	if(!f)
	{
		cout<<0;
		return 0;
	}
	int r=n,l=1;
	while(l<=r)
	{
		while(num[l])
		{
			if(l>r) break;
			if(c[l]==c[r])
			{
				if(num[l]==num[r])
				{
					l++;
					r--;
				}
				else if(num[l]<num[r])
				{
					num[r]-=num[l];
					c[l]=c[r];
					l++;
				}else
				{
					num[l]-=num[r];
					c[r]=c[l];
					r--;
				}
			}
			else
			{
				if(num[l]==num[r])
				{
					sum+=num[l];
					l++;
					r--;
				}
				else if(num[l]<num[r])
				{
					sum+=num[l];
					num[r]-=num[l];
					c[l]=c[r];
					l++;
				}else
				{
					sum+=num[r];
					num[l]-=num[r];
					c[r]=c[l];
					r--;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

