#include<bits/stdc++.h>
using namespace std;
long long t,j,n,m,i,a[10001];
int ans=-2;
int num=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	
	{
		cin>>a[i];
		sort(a+1,a+n+1);
		for(long long i=1;i<=n;i++)
		ans++;
		for(long long j=1;j<=n;j++)
		if(i==j);
		
		{
			if(a[i]<a[j]&&a[i]-a[j]<=t)
			{
			
				t=t-(a[i]-a[j]);
				
			}
			else
				break;
		}
		num=max(num,ans);
		ans++;
	}
	cout<<ans;
	return 0;
 } 
