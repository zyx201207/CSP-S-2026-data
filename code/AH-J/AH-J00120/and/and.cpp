#include<bits/stdc++.h>
using namespace std;
int n,m,ans,t,a[200010];
bool pd,w[200010];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=30;i>=1;--i)
	{
		int mod=pow(2,i),tot=0;
		for(int j=1;j<=n;++j)
		{
			int d=a[j]%mod-a[j]%(mod/2);
			tot+=(d&&!w[j]);
		}
		if(tot>=m)
		{
			for(int j=1;j<=n;++j)
			{
				int d=a[j]%mod-a[j]%(mod/2);
				if(!d)
				{
					w[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!w[i])
		{
			if(!pd)
			{
				ans=a[i];
				pd=1;
			}
			else
			{
				ans&=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
