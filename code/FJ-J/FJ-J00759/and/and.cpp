#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int n,m,ai,ans;
bool vis[maxn];
bool a[maxn][40];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>ai;
		int ct=31;
		while(ai!=0)
		{
			a[i][--ct]=(ai&1);
			ai>>=1;
		}
	}
	for(int t=1;t<=30;++t)
	{
		int res=0;
		for(int i=1;i<=n;++i)
		{
			if(vis[i]) continue;
			if(a[i][t]) ++res;
		}
		if(res>=m)
		{
			for(int i=1;i<=n;++i)
			{
				if(vis[i]) continue;
				if(!a[i][t]) vis[i]=1;
			}
			ans+=(1<<(30-t));
		}
	}
	cout<<ans;
	return 0;
} 
