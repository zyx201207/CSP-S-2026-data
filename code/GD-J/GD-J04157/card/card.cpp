#include<iostream>
using namespace std;
int n,m;
int a[500012],last[500012],f[5012][5012],ans[500012];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		int v=last[a[i]];
		if(v==0)
		{
			v=i;
			for(int j=1;j<=m;j++)f[i][j]=f[last[a[i+1]]][j];
			f[i][a[i]]=1;
			last[a[i]]=i;
		}
		for(int j=1;j<=m;j++)ans[j]+=f[v][j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
