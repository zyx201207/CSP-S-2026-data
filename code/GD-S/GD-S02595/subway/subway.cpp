#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],t;
struct subway
{
	int cost,to;
}a[505][500005];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		t=max(k,t);
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j].to>>a[i][j].cost;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=t;j++)
		{
			if(a[i][j].to==a[i+1][j].to)
			{
				a[i][j].cost==min(a[i][j].cost,a[i+1][j].cost);
				a[i+1][j].cost==a[i][j].cost;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int start,end,sum=0;
		cin>>start>>end;
		sum+=w[start];
		sum+=w[end];
		for(int j=start;j<=end;j++)
		{
			sum+=a[n][j].cost;
		}
		cout<<sum<<endl;
	}
	return 0;
}
