#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
// c数据 n线路 m站数 d max{len线路} q数据数 

struct metro{
	long long xian,ti;
};
map<long long,vector<metro> > mp;

long long mmin(long long a,long long b)
{
	if(a<=b)return a;
	return b;
}

long long walk[500005],sz[505];
long long floyd[505][505];//地铁i换地铁j最小步行距离 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(floyd,0x3f,sizeof floyd);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>walk[i];
	for(int i=1;i<=n;i++)
	{
		floyd[i][i]=0;
		cin>>sz[i];
		for(int j=1;j<=sz[i];j++)
		{
			long long id,jl;
			cin>>id>>jl;
			mp[id].push_back({i,jl});
		}
	}
	
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		for(auto i:it->second)
		{
			for(auto j:it->second)
			{
				floyd[i.xian][j.xian]=mmin(floyd[i.xian][j.xian],i.ti+j.ti);
			}
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				floyd[i][j]=mmin(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
	}
	
	long long ans=0;
	while(q--)
	{
		ans=1e18+114514;
		int sta,end;
		cin>>sta>>end;
		for(auto i:mp[sta])
		{
			for(auto j:mp[end])
			{
				ans=min(ans,floyd[i.xian][j.xian]+i.ti+j.ti);
			}
		}
		cout<<ans+walk[sta]+walk[end]<<"\n";
	}
	return 0;
}
//Oct31==Dec25?
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

//finish at 16:19
