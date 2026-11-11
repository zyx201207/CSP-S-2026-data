#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[500005],b[500005],ans[500005],d[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];lst[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		d[i]=1;
		if(b[a[i-1]]==i-1) d[i]+=d[i-1];
		d[i]+=d[lst[i]];
	}
	for(int i=n;i>=1;i--)
	{
		if(b[a[i]]==i) ans[a[i]]=d[i];
	}
	for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
	return 0;
}
