#include <bits/stdc++.h>
using namespace std;
long long a[2000005],d[2000005];
int c,t,sum=1;
long long num(int n,int k)
{
	long long cnt=0;
	bool flag=true;
	for(int i=sum;i<=n-3;i++)
	{
		for(int j=i+1;j<=j+3;j++)
		{
			if(d[j]>k) flag=false;
			else if(d[j-1]+d[j]<=k) flag=false;
		}
		if(flag) cnt++;
	}
	return cnt;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int x=1;x<=t;x++)
	{
		int n;
		long long k;
		cin >> n >> k;
		n+=sum;
		cin >> a[sum];
		for(int i=sum+1;i<n;i++)
		{
			cin>> a[i];
			d[i]=a[i]-a[i-1];
		}
		cout<<num(n,k)<<endl;
	}
	return 0;
}
