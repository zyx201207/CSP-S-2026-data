#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5+5;
int a[N]; 
vector<int> box;
int vis[N];
int ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n>>m;
	int idx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		idx=max(idx,a[i]);
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				box.push_back(a[j]);
				vis[a[j]]=j;
			}
			else
			{
				int x=box.size()-1;
				for(int k=vis[a[j]];k<=x;k++)
				{
					if(vis[box[k]]==k+1) vis[box[k]]=0;
					box.pop_back();
				}
			} 
		}
		for(int i=1;i<=idx;i++)
		{
			if(vis[i]!=0) ans[i]++;
		}
		box.clear();
		memset(vis,false,sizeof vis);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

