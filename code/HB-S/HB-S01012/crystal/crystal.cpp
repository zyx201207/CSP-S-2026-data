#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long a[500000]={0};
	int n;
	long m;
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	for(int i=0;i<n;i++)
	{
		int k=m;
		int sum=0;
		long j=i;
		long t=0;
		while(k>=0&&j>=0&&i!=0)
		{
			sum++;
			j--;
			t=a[i]-a[j];
			k=k-t;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
