#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
vector<int>a[1000001];
/*void dfs(int x)
{
	
}*/
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
    {
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(c==1)
		{
			if(k==n)cout<<0<<'\n';
			else if(k>=2)cout<<1<<'\n';
			else
			{
				bool flag=0;
				for(int i=1;i<=n;i++)
				  if((int)a[i].size()==n-1)flag=1;
				if(flag)cout<<1<<'\n';
				else cout<<2<<'\n';
			}
		}
		else if(c==13 or c==14)
		{
			if(k==1)cout<<(n+3)/4<<'\n';
			else if(n==k)cout<<0<<'\n';
			else if(k>=n/2)cout<<1<<'\n';
			else cout<<max((n-2*k+6)/8+1,1)<<'\n';
			continue;
		}
		else
		{
			if(n==k)cout<<0<<'\n';
			else if(k*2+1>=n)cout<<1<<'\n';
			else cout<<2<<'\n';
		}
	}
	return 0;
}
