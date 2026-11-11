#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],s=0,max1=-1,c=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		s=0;
		c=1;
		for(int j=i-1;j>=0;j--)
		{
			s+=a[i]-a[j];
			if(s>m)
			{
				break;
			}
			c+=1;
		}
		if(c>=max1)
		{
			max1=c;
		}
	}
	cout<<max1;
	return 0;
}
