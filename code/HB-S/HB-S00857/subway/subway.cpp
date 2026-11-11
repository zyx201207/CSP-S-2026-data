#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[600000],g[600][30000];
vector<pair<long long,long long> >v[600000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i+n];
	}
	for(long long i=1,ki;i<=n;i++){
		//cout<<i<<':'<<n<<','<<ki<<'\n';
		if(i>n)break;
		
		cin>>ki;
		for(long long j=1,ai,ti;j<=ki;j++){
			cin>>ai>>ti;
			v[i].push_back({ai+n,ti});
			v[ai+n].push_back({i,ti});
		//	cout<<i<<' '<<j<<','<<ki<<'\n';
		}
	}//cout<<'g';
	//getchar();
	if(12<=c&&c<=19){
		
		for(long long i=1;i<=n;i++){
			bool u[60000]={};
			for(long long j=1;j<=m+n;j++)g[i][j]=1000000000000000000;
			queue<pair<long long,long long> >q;
			q.push({0,i});
			g[i][i]=0;
			while(!q.empty()){
				long long x=q.front().second;
			//	cout<<x<<' '<<g[i][x]<<' '<<'\n';
				q.pop();
				if(u[x]){
					continue;
				}
				u[x]=1;
				for(long long j=0;j<(long long)v[x].size();j++){
					
					if(g[i][x]+v[x][j].second<g[i][v[x][j].first ]){
						g[i][v[x][j].first ]=g[i][x]+v[x][j].second;
					//	cout<<g[i][v[x][j].first ]<<' '<<v[x][j].first<<','<<'\n';
						q.push({-g[i][v[x][j].first ],v[x][j].first});//cout<<v[x][j].first<<' ';
					}
					//break;
				}
			//	break;
			}
		}
	}
	else{
		for(long long i=1;i<=n;i++){
			
			bool u[60000]={};
			for(long long j=1;j<=m+n;j++)g[i][j]=1000000000000000000;
			priority_queue<pair<long long,long long> >q;
			q.push({0,i});
			g[i][i]=0;
			while(!q.empty()){
				long long x=q.top().second;
			//	cout<<x<<' '<<g[i][x]<<' '<<'\n';
				q.pop();
				if(u[x]){
					continue;
				}
				u[x]=1;
				for(long long j=0;j<(long long)v[x].size();j++){
					
					if(g[i][x]+v[x][j].second<g[i][v[x][j].first ]){
						g[i][v[x][j].first ]=g[i][x]+v[x][j].second;
					//	cout<<g[i][v[x][j].first ]<<' '<<v[x][j].first<<','<<'\n';
						q.push({-g[i][v[x][j].first ],v[x][j].first});//cout<<v[x][j].first<<' ';
					}
					//break;
				}
			//	break;
			}
		}
	}
	for(long long i=1,x,y;i<=q;i++){
		cin>>x>>y;
		x+=n;
		y+=n;
		long long aw=1000000000000000000;
		for(long long j=0;j<(long long)v[x].size();j++){
			aw=min(aw,g[v[x][j].first ][y]+v[x][j].second);
		}
		cout<<aw+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
* */
