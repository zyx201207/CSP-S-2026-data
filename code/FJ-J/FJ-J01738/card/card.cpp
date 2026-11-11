#include<bits/stdc++.h>
using namespace std;
stack <int> st;
int n,m;
int a[500100],b[500100],sum[500100];
int vis[500100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		vis[b[i]]++;
		st.push(b[i]);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			while(vis[j]>0)
			{
				vis[st.top()]--;
				st.pop();
			}
			st.push(j);
			vis[j]=1;
		}
		while(!st.empty())
		{
			sum[st.top()]++;
			st.pop();
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			st.push(b[i]);
			vis[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
