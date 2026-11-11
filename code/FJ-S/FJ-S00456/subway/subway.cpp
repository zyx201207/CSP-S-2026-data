#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[600000],a[501][50000],t[501][50000],r[60000][10];
void dfs(int u,int l,int cnt)
{
	if(u==ed)
	{
		if(sum) ans=min(ans,cnt);
		else ans=cnt;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i][0];j++)
		{
			if(a[i][j]==u) dfs(u+1,l+1,cnt);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>r[i][1]>>r[i][2];
	//cout<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<endl;
	//for(int i=1;i<=m;i++) cout<<w[i]<<" ";
	//cout<<endl;
	//for(int i=1;i<=n;i++)
	//{
	//	cout<<a[i][0]<<" ";
	//	for(int j=1;j<=a[i][0];j++) cout<<a[i][j]<<" "<<t[i][j]<<" ";
	//	cout<<endl;
	//}
	//for(int i=1;i<=q;i++) cout<<r[i][1]<<" "<<r[i][2]<<endl;
	for(int i=1;i<=q;i++)
	{
		int ans=w[r[i][1]]+w[r[i][2]];
		int st=r[i][2];
		int ed=r[i][2];
		int sum=0;
		dfs(r[i][1],1,ans);
		cout<<ans<<endl;
	}
}
