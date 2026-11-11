#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
int a[N];
bool vis[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx = max(maxx,a[i]);
	}
	int wei=0;
	while(maxx)
	{
		maxx = maxx >> 1;
		wei ++;
	}
	// wei --;
	int ans = 0;
	memset(vis,1,sizeof vis);
	while(wei)
	{
		int num = 0;
		for(int i=1;i<=n;i++)
		{
			if((a[i]>>wei)&&vis[i]==1)
			{
				num++;
				// cout<<a[i]<<endl;
			}
		}
		//cout<<num;
		if(num>=m)
		{
			ans+=pow(2,wei);
			// cout<<ans<<endl;
			for(int i=1;i<=n;i++)
			{
				if(!(a[i]>>wei))
				{
					vis[i]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if((a[i]>>wei))
			{
				a[i]-=pow(2,wei);
			}
		}
		wei --;
	}
	int num = 0;
	for(int i=1;i<=n;i++)
	{
		if((a[i]>>wei)&&vis[i]==1)
		{
			num++;
		}
	}
	if(num>=m)
	ans++;
	cout<<ans;
	return 0;
}
