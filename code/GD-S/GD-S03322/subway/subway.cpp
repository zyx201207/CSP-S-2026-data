#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,f;
int a[50005],v[50005];
int sum;
int z,w;
int k;
void dfs(int s,int mo)
{
	for(int i=1;i<=y;i++)
	{
		sum+=a[i]+v[i];
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>x>>y>>f;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	for(int i=1;i<=2*k;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=f;i++)
	{
		sum=0;
		cin>>z>>w;
		dfs(z,w);
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
