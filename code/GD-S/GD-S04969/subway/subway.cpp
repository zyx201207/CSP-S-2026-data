#include<bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
long long w[500007]{};

vector<vector<pair<long long, long long>>> G;
//map<pair<long long, long long>, pair<long long, long long>> m;

long long a[500007]{};
long long jjd=1e12+7;
//long long w1[20007]{};

long long INF=500030;

long long zuo=0;

map<pair<long long, long long>, long long> num;
long long jsq=0;

long long fenpei(long long x, long long y)
{
	
	if(num.find({x, y})==num.end())
	{
		
		jsq++;
		num[{x, y}]=jsq;
		
		return jsq;
		
	}
	else
	{
		
		return num[{x, y}];
		
	}
	
}

long long dij(long long s, long long t)
{
	
	//cout<<s<<endl;
	
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
	
	vector<long long> d(jsq+7, jjd);
	vector<bool> flag(jsq+7, false);
	
	//q.push({0, s});
	for(long long i=1;i<=n;i++)
	{
		
		d[fenpei(s+INF, s+INF)]=0;
		q.push({0, fenpei(s+INF, s+INF)});
		
	}
	
	vector<long long> vis(jsq+7); 
	
	while(!q.empty())
	{
		
		auto now=q.top();
		q.pop();
		
		long long u=now.second;
		
		if(flag[u]==true)
		{
			
			continue;
			
		}
		
		flag[u]=true;
		
		for(auto pa:G[u])
		{
			
			if(d[pa.first]>d[u]+pa.second)
			{
				
				//vis[u]=pa.first.first;
				d[pa.first]=d[u]+pa.second;
				q.push({d[pa.first], pa.first});
				
			}
			
		}
		
	}
	
	/*for(auto pa:G[2])
	{
		
		cout<<pa.first<<" "<<pa.second<<endl;
		
	}*/
	
	//cout<<G[2][0].second<<endl;
	//cout<<d[INF+2+1]<<endl;
	
	long long MAX=jjd;
	
	//cout<<d[fenpei(3+INF, 3+INF)]<<endl;
	
	for(long long i=1;i<=n;i++)
	{
		
		MAX=min(MAX, d[fenpei(t+INF, t+INF)]);
		
	}
	
	//cout<<s<<" "<<w[1]<<endl;
	
	return w[s]+w[t]+MAX;
	
}

int main()
{
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>c>>n>>m>>d>>q;
	//scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	
	G.resize(m+INF+n);
	
	for(long long i=1;i<=m;i++)
	{
		
		cin>>w[i];
		
	}
	
	//cout<<w[1]<<endl;
	
	//bool tepan=false;
	//int panyi=-1;
	
	for(long long i=1;i<=n;i++)
	{
		
		long long k;
		
		cin>>k;
		
		long long W;
		
		for(long long j=1;j<=k;j++)
		{
			
			zuo++; 
			cin>>a[j]>>W;
			
			//cout<<W<<" "<<panyi<<endl;
			
			/*if(panyi==-1)
			{
				
				panyi=W;
				
			}
			else if(panyi!=W)
			{
				
				tepan=true;
			}
			*/	
			
			if(j>1)
			{
				
				G[fenpei(i, a[j])].push_back({fenpei(i, a[j-1]), 0});
				G[fenpei(i, a[j-1])].push_back({fenpei(i, a[j]), 0});
				
			}
			
			G[fenpei(i, a[j])].push_back({fenpei(a[j]+INF, a[j]+INF), W});
			G[fenpei(a[j]+INF, a[j]+INF)].push_back({fenpei(i, a[j]), W});
			
		}
		
	}
	
	//cout<<w[1]<<endl;
	
	long long x, y;
	
	//cout<<tepan<<endl;
	
	while(q--)
	{
		
		//vector<vector<pair<long long, long long>>> rG=G;
		
		cin>>x>>y;
		
		/*if(tepan==true)
		{
			
			cout<<di(x, y)<<endl;
			
		}
		else
		{
			
			cout<<bfs(x, y)<<endl;
			
		}*/
		
		cout<<dij(x, y)<<endl;
		//printf("%lld\n", dij(x, y));
		
	}
	
	return 0;
	
}
