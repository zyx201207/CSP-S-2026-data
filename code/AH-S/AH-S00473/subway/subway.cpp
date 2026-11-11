#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int stp[N];
vector<pair<int,int>> ltp[500],ptl[N];
map<pair<int,int>,int> M;
int dist[500][500];
int f[500][500][500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)  cin>>stp[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int s,t;
			cin>>s>>t;
			ltp[i].push_back({t,s});
			ptl[s].push_back({t,i});
		}	
	}	
	
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++) dist[i][i]=0;
	
	memset(f,0x3f,sizeof f);
	
	for(int i=1;i<=m;i++) {
		for(auto x:ptl[i]) 
		{
			for(auto y:ptl[i])
			if(x.second!=y.second)
			{
				int i=x.second,j=y.second;
				
				f[0][i][j]=min(f[0][i][j],x.first+y.first);
				f[0][j][i]=min(f[0][j][i],x.first+y.first);
			}	
		}	
	}
	
	//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
	
	
	for(int i=1;i<=n;i++) f[0][i][i]=0;
	
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				
				f[k][i][j]=f[k][j][i]=f[k-1][i][j];
				if(f[k-1][i][j]>f[k-1][i][k]+f[k-1][k][j])
				{
					f[k][i][j]=f[k-1][i][k]+f[k-1][k][j];
					f[k][j][i]=f[k-1][i][k]+f[k-1][k][j];
				}	
			}	
			
	map<pair<int,int>,int> Ma;
		
	while(q--)
	{
		int x,y;
		int minn=0x3f3f3f3f;
		cin>>x>>y;
		if(Ma.count({x,y})||Ma.count({y,x})) {cout<<Ma[{x,y}]<<'\n';continue;}
		for(auto t1:ptl[x])
			for(auto t2:ptl[y])
			{
				int sum=0;
				sum=f[n][t1.second][t2.second];
				sum+=stp[x]+stp[y];
				sum+=t1.first+t2.first;
				minn=min(minn,sum);
			}	
		Ma[{x,y}]=Ma[{y,x}]=minn;
		cout<<minn<<'\n';
	}	
			
			
	
	return 0;
}	
