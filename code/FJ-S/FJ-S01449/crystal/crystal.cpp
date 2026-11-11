#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000086],ans,mx;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(long long i=0;i<n;i++)
	{
		ans=1;
		for(long long j=i;j<n;j++)
		{
			if(m==0)break;
			if(a[j]<=a[i])
			{
				if(m-a[i]+a[j]>=0)
				{
					m=m-a[i]+a[j];
					ans++;
				}
			}
		}
		mx=max(mx,ans);
	 } 
	cout<<mx;
	return 0; 
}
