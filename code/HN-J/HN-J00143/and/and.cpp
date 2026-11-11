#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],vis[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i]=1;
	}
	int cnt=n,ans=0;
	for(int i=30;i>=0;i--)
	{
		vector<int>l;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0)
				continue;
			if((a[j]&(1<<i))==0)
				cnt--,vis[j]=0,l.push_back(j);
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			continue;
		}
		for(auto x:l)
		{
			cnt++;
			vis[x]=1;
		}
	}
	cout<<ans;
	return 0;
}
