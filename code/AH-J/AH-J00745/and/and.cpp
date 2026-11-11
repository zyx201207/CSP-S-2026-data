#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200010];
bool u[200010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	for(int i=30;i>=0;i--)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(u[j]==0)
			{
				if((a[j]&(1<<i)))
				{
					cnt++;
				}
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;j++)
			{
				if(u[j]==0)
				{
					if(!(a[j]&(1<<i)))
					{
						u[j]=1;
					}
				}
			}
		}	
	}
	cout<<ans;
	return 0;
}
