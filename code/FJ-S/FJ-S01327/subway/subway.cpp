#include<bits/stdc++.h> 
using namespace std;
struct node
{
	long long z,t,k;
}a[500050];
long long w[500050],ww[500050],b[501][12501],c,n,m,d,q,l[500050],r[500050],f[2501][2501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		ww[i]=w[i]+ww[i-1]; 
//		cout<<ww[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++)
		{
			cin>>a[i].z>>a[i].t;
			b[a[i].z][i]=a[i].t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=ww[max(i,j)]-ww[min(i,j)-1]+w[max(i,j)];
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			for(int o=1;o<=n;o++)
			{
				if(!b[i][o]||!b[j][o])continue;
				f[i][j]=min(f[i][j],ww[i]+b[i][o]+b[j][o]+w[j]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=min(f[i][j],f[j][i]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=q;i++)cout<<f[l[i]][r[i]]<<endl;
	return 0;
}
