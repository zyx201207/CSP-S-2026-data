#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,k,sum;
int mp[2000005]; 
void dfs(int w,int m)
{
	if(m==k)
	{
		sum=w*m-k*2;
		return;
	}
	mp[w]=1;
	for(int i=1;i<=n;i++)
	{
		if(mp[i])	continue;
		dfs(i,m+1);
	}
	mp[w]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		int u[n+5],v[n+5];
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
		}
		for(int i=1;i<=n;i++)
		{
			dfs(i,1);
		}
		cout<<ceil(sum/(k*2*1.5))<<"\n";
	}
	return 0;
}
/*
	哈，谁能告诉我那些公式的含义!_!。呜呜呜，妈妈信息学水太深，
	我要走中考@_@ 
*/
