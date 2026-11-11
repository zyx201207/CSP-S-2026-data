#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[300005],c[500005],d[500005],e[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(b[a[i]]) c[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) d[j]=0;
		for(int j=i;j<=n;j++)if(c[j]>0 && c[j]>=i)d[c[j]]--,d[j]++;
		for(int j=i;j<=n;j++)
		{
			d[j]+=d[j-1];
			if(d[j]>=0) e[a[j]]++;
			cout<<d[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<e[i]<<" ";
	return 0;
}
