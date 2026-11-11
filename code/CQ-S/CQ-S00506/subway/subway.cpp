#include<bits/stdc++.h>
#include<vector> 
using namespace std;
int c,n,m,d,q,w[500009],a[10009][10009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++)
	{
		for(int o=1;o<=m;o++)
		{
			if(o!=j)
			{
				a[o][j]=1e9;
			}
			else
			{
				a[o][j]=0;
			}
		}
	} 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,p[100000],q[100000];
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>p[j]>>q[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int o=j;o<=k;o++)
			{
				a[p[o]][p[j]]=a[p[j]][p[o]]=q[o]+q[j];
			}
		 } 
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--)
	{
		int qd,zd;
		cin>>qd>>zd;
		cout<<a[qd][zd]+w[qd]+w[zd]<<"\n";
	}
	return 0;
}

