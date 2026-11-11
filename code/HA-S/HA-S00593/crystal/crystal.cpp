#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],tans,ans,m1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		m1=m;
		ans=0;
		for(int j = i;j>=1;j--)
		{
			m1-=(a[i]-a[j]);
			if(m1<0)
			{
				break;
			}
			ans++;
		}
		tans=max(tans,ans);
	}
	cout<<tans;
	return 0;
 } 
