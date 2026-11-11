#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m;
long long a[1005];
int maxn=-1;
int xb;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		if(maxn<(a[i]-a[i-1]))
		{
			maxn=a[i]-a[i-1];
			xb=i;
		}
	}
	a[xb]=1e13;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1e13)
		{
			break;
		}
		//cout<<a[i]<<" ";
		int num=0;
		for(int j=0;j<=i;j++)
		{
			num+=(a[i]-a[j]);
		}
		if(num<=m&&ans<=i)
		{
			ans=i+1;
		}
		
	}
	cout<<ans;
}
