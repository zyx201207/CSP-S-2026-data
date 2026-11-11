#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int f[N];
int ans[M];
int rig[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		rig[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]++;
		ans[a[i]]+=f[i];
		f[rig[a[i]]+1]+=f[i];
//		cout<<pos[a[i]]<<"->";
//		for(int j=1;j<=m;j++)
//		{
//			cout<<"("<<g[j].id<<":"<<query(g[j].rk)<<") ";
//		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
}

