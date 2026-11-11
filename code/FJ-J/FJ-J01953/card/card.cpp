#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int a[500010];
int ans[500100];
bool st[500010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) st[j]=0;
		for(int j=1;j<i;j++) st[j]=1;
		for(int j=i;j<=n;j++)
		{
			bool ok=true;
			for(int k=i;k<j;k++)
			{
				if(a[k]==a[j]) ok=false;
				if(ok==false) st[k]=1;
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int j=1;j<=n;j++)
			{
				if(st[j]==0&&a[j]==k) ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
