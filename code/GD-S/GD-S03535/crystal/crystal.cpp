#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[100005],sum=0,ans1=0,ans2=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%n==0)sum=sum/n;
	else sum=sum/n+1;
	int xi;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=sum)xi=i;
	}
	long long m1=m,m2=m;
	for(int i=xi;i>=1;i--)
	{
		
		if(m1<1)break;
		if(a[i]==sum)
		{
			ans1++;
		}
		else if(a[i]!=sum&&m1-(sum-a[i])>=0)
		{
			ans1++;
			m1-=(sum-a[i]);
		}
	}
	for(int i=xi;i>=1;i--)
	{
		if(m2<1)break;
		if(a[i]==a[xi])
		{
			ans2++;
		}
		else if(a[i]!=a[xi]&&m2-(a[xi]-a[i])>=0)
		{
			ans2++;
			m2-=(a[xi]-a[i]);
		}
		else break;
	}
	ans1=max(ans1,ans2);
	cout<<ans1;
 } 
