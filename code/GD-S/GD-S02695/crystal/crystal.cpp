#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i+ans>=n) break;
		long long have=m;
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
		}
		while(1)
		{
			int id=upper_bound(b+1,b+n+1,b[i])-b;
			long long sum=(id-i)*(b[id]-b[i]);
			if(sum>have||sum<=0)
			{
				ans=max(ans,id-i);
				break;
			}
			have-=sum;
			for(int j=i;j<id;j++)
			{
				b[j]=b[id];
			}
		}
	}
	cout<<ans;
	return 0;
}
