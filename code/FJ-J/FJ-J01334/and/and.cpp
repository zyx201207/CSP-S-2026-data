#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],ans=0,cnt=0,sw;
	string c[200005],b[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i]>=1)
		{
			c[i]+=a[i]%2+'0';
			a[i]/=2;
		}
		for(int j=c[i].size();j>=0;j--)
		{
			b[i]+=c[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int p=max(b[i].size(),b[j].size());
			sw=1;
			for(int k=p;k>0;k--)
			{
				if(b[i][k]=='1'&&b[j][k]=='1')
				{
					cnt+=sw;
				}
				//sw*=2;
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	
	return 0;
}
