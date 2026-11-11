#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500078];
int ans[300078];
int v[300078];
stack<int>z;
void cp(int x)
{
	if(v[x])
	{
		while(z.top()!=x)z.pop();
	}
	else
	{
		v[x]=1;
		z.push(x);
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		memset(v,0,sizeof(v));
		for(int j=i;j<n;j++)
			cp(a[j]);
		while(!z.empty())
		{
			ans[z.top()]++;
			z.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
