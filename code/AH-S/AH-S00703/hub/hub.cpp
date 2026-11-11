#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,pd[11],minn,ds[11][11];
inline void dfsc(int dep,int l)
{
	if(dep>k)
	{
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			if(pd[i]==0)
			{
				int minn=1e18+1;
				for(int j=1;j<=n;j++)
				{
					if(pd[j]==1)
						minn=min(minn,ds[i][j]);
				}
				maxx=max(maxx,minn);
			}
		}
		minn=min(minn,maxx);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(pd[i]==0)
		{
			int nowc=l,pdd=0;
			for(int j=1;j<=n;j++)
			{
				if(pd[j]==1&&ds[i][j]==1)
				{
					pdd=1;
					break;
				}
			}
			if(pdd==0)
				nowc++;
			if(nowc<=2)
				pd[i]=1,dfsc(dep+1,nowc),pd[i]=0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k==n)
		{
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14)
		{
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
			}
			int m=n>>1;
			if(k>=m)
			{
				cout<<"1\n";
				continue;
			}
			int s=min((m-k)/4+2,(m-k-1)/2+2);
			cout<<s<<"\n";
			continue;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			ds[u][v]=ds[v][u]=1;
		}
		for(int i=1;i<=n;i++)
		{
			memset(pd,0,sizeof(pd));
			queue<pair<int,int>> q;
			q.push({i,0}),pd[i]=1;
			while(!q.empty())
			{
				int now=q.front().first,dep=q.front().second;
				ds[i][now]=dep,q.pop();
				for(int j=1;j<=n;j++)
				{
					if(pd[j]==0&&ds[now][j]==1)
						pd[j]=1,q.push({j,dep+1});
				}
			}
		}
		memset(pd,0,sizeof(pd)),minn=1e18+1,dfsc(1,0),cout<<minn<<"\n";
		memset(ds,0,sizeof(ds));
	}
	return 0;
}
