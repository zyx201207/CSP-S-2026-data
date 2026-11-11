#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],nw;
bool op[200005];
struct bucket
{
	int cnt[40];
}v,null;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=30;j++)
		{
			if((a[i]>>j)&1)
			{
				v.cnt[j]++;
			}
		}
	}
	nw=n;
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		if(v.cnt[i]>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;j++)
			{
				if(!((a[j]>>i)&1)&&!op[j])
				{
					op[j]=true;
					for(int k=0;k<=30;k++)
					{
						if((a[j]>>k)&1)
						{
							v.cnt[k]--;
						}
					}
					nw--;
				}
			}
		}
	}
	cout<<ans;
}
