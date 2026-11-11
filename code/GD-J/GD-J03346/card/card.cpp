#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool vis[500005];
int ans[300005];
int b[500005],now;
int fi[500005];
//Remember to clear!!!
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
		{
			b[++now]=a[j];
			if(!fi[b[now]])
			{
				fi[b[now]]=now;
				vis[b[now]]=true;
				continue;
			}
			while(now>fi[a[j]])
			{
				vis[b[now]]=false;
				if(fi[b[now]]==now) fi[b[now]]=0;
				--now;
			}
			vis[b[now]]=true;
		}
		now=0;
		for(int j=1; j<=m; j++)
		{
			ans[j]+=vis[j];
			vis[j]=false;
			fi[j]=0;
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
/*
Ô¤¹À 100+100+100+48=348
O(n^2+nm)
*/ 
