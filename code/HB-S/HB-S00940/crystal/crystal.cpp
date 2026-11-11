#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[500005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long x=a[0];
	for(int i=0;i<n;i++)
	{
		a[i]-=x;
	}
	int res=1;
	long long mm=m;
	for(int i=0;i<n;i++)
	{
		mm=m;
		int ans=1;
		for(int j=i+1;j<n;j++)
		{
			if(ans*(a[j]-a[j-1])<=mm)
			{
				mm=mm-ans*a[j]+ans*a[j-1];
				ans++;
			}
			else
			{
				break;
			}
		}
		if(ans>res)
		{
			res=ans;
		}
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
