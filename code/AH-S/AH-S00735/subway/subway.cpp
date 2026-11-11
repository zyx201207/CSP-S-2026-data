#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500002],y[500002],s=0,mi=INT_MAX,jq,jz;
long long p1=0,p2=0;
struct e{
	int x,v;
}a[501][500002];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>y[i];
		for(int j=0;j<y[i];j++)
		{
			cin>>a[i][j].x>>a[i][j].v;
		}
	}
	for(int i=1;i<=q;i++)
	{
		mi=INT_MAX;
		cin>>p1>>p2;
		if(p1==p2)
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			s=0;
			for(int k=0;k<y[j];k++)
			{
				if(a[j][k].x==p2)
				{
					jz=k;
					s+=1;
				}
				if(a[j][k].x==p1)
				{
					jq=k;
					s+=1;
				}
			} 
			if(s==2)
			{
				if(mi>=w[p1]+w[p2]+a[j][jq].v+a[j][jz].v)
				{
					mi=w[p1]+w[p2]+a[j][jq].v+a[j][jz].v;
				}
			}
		}
		cout<<mi<<endl;
	}
	return 0;
}
