#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,x,y;long long w[500001],mapp[501][501],t,ans,s;
vector<int>zhan[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a,zhan[a].push_back(i);
		for(int j=1;j<=k;j++)
			cin>>t;
	}
	for(int i=1;i<=n;i++)
		mapp[i][i]=2*t;
	for(int i=1;i<=m;i++)
		for(int j=0;j<zhan[i].size();j++)
			for(int l=j+1;l<zhan[i].size();l++)
				mapp[zhan[i][j]][zhan[i][l]]=4*t;
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			if(i!=l&&mapp[i][l]>0)
				for(int j=1;j<=n;j++)
					if(j!=l&&mapp[l][j]>0)
						mapp[i][j]=(mapp[i][j]>0?min(mapp[i][j],mapp[i][l]+mapp[l][j]):(mapp[i][l]+mapp[l][j]));
	while(q--)
	{
		cin>>x>>y,ans=1e18;
		for(int i=0;i<zhan[x].size();i++)
		{
			s=w[x]+w[y];
			for(int j=0;j<zhan[y].size();j++)
				ans=min(ans,s+mapp[zhan[x][i]][zhan[y][j]]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
