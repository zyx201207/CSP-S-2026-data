#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt,c[200005],ans;
bool f[1048578][21];
void fj(int x,int y)
{
	int cnt=0;
	while(x!=0)
	{
		f[y][++cnt]=x%2;
		x/=2;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fj(a[i],a[i]);
	}
	for(int k=20;k>=0;k--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]][k]==1) c[++cnt]=a[i];
		}
		if(cnt<m) continue;
		for(int i=1;i<=cnt;i++) a[i]=c[i];
		n=cnt;
		if(cnt==m) break;
	}
	ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	cout<<ans;
}
