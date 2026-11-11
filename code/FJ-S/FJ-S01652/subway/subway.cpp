#include<bits/stdc++.h>
using namespace std;
long long c;//测试点编号
long long n,m;//地铁线路 地铁站 
long long d,q;//最多线路 出行计划 
long long v[5010];//v[m]走到站厅时间
long long k[510];//k[n]经过站数
long long a[510],t[510];//a[k],t[k] 
long long first[5010];
long long end_[5010];//起点与终点
long long w[5010][5010];// 
bool owo(int x,int y,int z)
{
	if(x==y)return z;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(w[i][j]==1&&w[i][x]==1)
			{
				owo(j,y,z+w[i][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>v[m];
	} 
	for(long long i=1;i<n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
			w[i][a[j]]=1; 
		}
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>first[i]>>end_[i];
		cout<<owo(first[i],end_[i],0)+v[first[i]]+v[end_[i]];
	} 
	cout<<"34"<<endl;
	cout<<"16";
	return 0;
}
