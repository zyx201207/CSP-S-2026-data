#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,f;
int a[50005],v[50005];
int sum=INT_MAX;
int z,w;
struct cn{
	long long one[1000005];
	long long second[1000005];
}str;
void dfs(int s,int mo)
{
	sum=min(sum,mo);
	for(int i=1;i<=y;i++)
	{
		
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		for(int j=1;j<x;j++)
		{
			cin>>str.one[i]>>str.second[i];
		}
		dfs(x,sum);
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
