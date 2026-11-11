#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int c,n,m,d,q;
int w[N];
long long dij[N][N];
bool flag[N],flag2[N];

//typedef pair<long long ,long long> pii;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector< pair<long long ,long long> > k[505],mp[N];
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			long long a,t;
			cin>>a>>t;
			k[i].push_back({t,a});
		}
		for(int x=0;x<ki;x++){
			for(int j=0;j<ki;j++){
				long long v=k[i][x].second,u=k[i][j].second;
				if(x!=j){
					mp[v].push_back({u, k[i][x].first + k[i][j].first + w[v] + w[u] });
					mp[u].push_back({v, k[i][x].first + k[i][j].first + w[v] + w[u] });
				} 
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dij[i][j]=1e18+5;
		}
		dij[i][i]=0;
	}
	int r;
	cin>>r;
	
	while(r--){
		int x,y;
		cin>>x>>y;
		if(flag2 == 0){
				for(int i=1;i<=m;i++){
					dij[x][i]=1e18+5;
					flag[i]=0;
				}
				priority_queue<pair<long long ,long long>,vector<pair<long long ,long long> >,greater<pair<long long ,long long> > > q;
				q.push({0ll,x});
				while(!q.empty()){
					long long now=q.top().second;
					q.pop();
					if(flag[now]) continue;
					flag[now]=1;
					for(auto xx : mp[now]){
						long long nxt=xx.second;long long val=xx.first;
						if(dij[x][now] + val < dij[x][nxt]){
							dij[x][nxt] = dij[x][now] + val;
							q.push({dij[x][nxt] , nxt});
						}
					}
				}
				flag2[x]=1;
			}
		cout<<dij[x][y]<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
