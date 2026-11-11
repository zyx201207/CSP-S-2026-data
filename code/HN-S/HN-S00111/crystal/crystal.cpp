#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10,maxl=5e3+10;
int n,m,ans;
int a[N];
int sum[maxl][maxl];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) sum[i][j]=((a[i]>=a[j])? a[i]-a[j]:-1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sum[i][j]>=0) sum[i][j]+=sum[i][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sum[i][j]==-1) continue;
			if(sum[i][j]<=m) ans=max(ans,j);
			else if(sum[i][j-1]<=m) ans=max(ans,j);
		}
	}
	cout<<ans;
	return 0;
}
//wo shi qu wo bu hui zuo
