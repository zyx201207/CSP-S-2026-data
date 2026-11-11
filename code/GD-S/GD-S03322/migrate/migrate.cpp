#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[50005];
int sum;
void dfs(int s)
{
	for(int i=1;i<=y;i++)
	{
		
	}
	
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		sum=0;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
			cin>>a[i];
		dfs(1);
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
