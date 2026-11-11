#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,ans;
int a[N];
int b[M];
vector<int> d[N];
bool vis[N];
int st[N],t;
void js(int kt)
{
	t=0;
	for(int i=1;i<=m;i++)
		vis[i]=0;
	for(int i=kt;i<=n;i++)
	{
		if(vis[a[i]]==1)
		{
			while(st[t]!=a[i])
				t--,vis[st[t]]=0;
		}
		st[t++]=a[i];
		vis[a[i]]=1;	
	}
	for(int i=0;i<t;i++)
		b[st[i]]++;
	return ;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n>10000)
	{
		int tt=0,f=1;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(x<a[tt]) f=0;
			if(x!=a[tt])
				a[++tt]=x;
		}
		if(f==1)
		{
			for(int i=1;i<=t;i++)
				cout<<i<<" ";
			return 0;
		}
		n=tt;
		for(int i=1;i<=n;i++)
			js(i);
		for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		js(i);
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
} 
