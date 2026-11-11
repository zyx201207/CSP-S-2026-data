#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
using namespace std;
vector<int>f[1000010];
int v[1000010],g[1000010];
void hs(int q,int w)
{
	v[q]=1;
	for(auto i:f[q])
		if(i!=w&&g[i]==1)
			hs(i,q);
}
void sh(int q,int w,int e)
{
	v[q]=min(v[q],e);
	for(auto i:f[q])
		if(i!=w)
			sh(i,q,e+1);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int fw,T,n,K,u,o;
	cin>>fw>>T;
	while(T--)
	{
		cin>>n>>K;
		for(int i=1;i<=n;i++)
			f[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>o;
			f[u].push_back(o);
			f[o].push_back(u);
		}
		int Min=2e18;
		for(int i=0;i<(1<<n);i++)
		{
			int s=0;
			fill(g+1,g+n+1,0);
			fill(v+1,v+n+1,0);
			for(int j=0;j<n;j++)
				if((i>>j)&1)
				{
					s++;	
					g[j+1]=1;				
				}
			if(s!=K)
				continue;
			s=0;
			for(int j=1;j<=n;j++)
				if(v[j]==0)
				{
					hs(j,0);
					s++;
				}
			if(s!=2)
				continue;
			fill(v+1,v+n+1,2e18);
			for(int j=1;j<=n;j++)
				if(g[j]==1)
					sh(j,0,0);
			s=0;
			for(int j=1;j<=n;j++)
				s=max(s,v[j]);
			Min=min(Min,s);
		}
		cout<<Min<<'\n';
	}
	return 0;
}

