#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int s[N];
int ans[N];
int vis[N];
int cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		memset (vis,0,sizeof vis);
		for (int j=i;j<=n;j++)
		{
			s[++cnt]=a[j];
			if (!vis[a[j]]||vis[a[j]]>=cnt)vis[a[j]]=cnt;
			else {
				
				cnt=vis[a[j]];
			}
		}
		for (int j=1;j<=cnt;j++)
		{
			ans[s[j]]++;
		}
	}
	for (int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
