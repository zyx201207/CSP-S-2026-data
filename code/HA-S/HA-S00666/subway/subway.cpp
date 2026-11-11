#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,t;
};
int w[500005];
int xian[505][20005];
int tu[505][505];
vector<node>v[505];
vector<int>fd[20005];
vector<int>dij[505][2];
int T;
int dis[505];
priority_queue <pair<int,int>,vector < pair < int,int > >,greater < pair < int,int > > > qq;
void dsl(int x){
	dis[x]=0;
	qq.push({0,x});
	while(!qq.empty()){
		int d=qq.top().second;
		int cha=qq.top().first;
		qq.pop();
		for(int i = 0;i<dij[d][0].size();i++){
			if(dis[dij[d][0][i]]>cha+dij[d][1][i]){
				dis[dij[d][0][i]]=cha+dij[d][1][i];
				qq.push({dis[dij[d][0][i]],dij[d][0][i]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			xian[i][a]=t;
			v[i].push_back({a,t});
			fd[a].push_back(i);
			T=t;
		}
	}
	if(n<=200){
		for(int i = 1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int k = 1;k<=m;k++){
					if(xian[i][k]!=0 && xian[j][k]!=0){
						if(tu[i][j]==0)tu[i][j]=xian[i][k]+xian[j][k];
						else tu[i][j]=min(tu[i][j],xian[i][k]+xian[j][k]);
					}
				}
			}
		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					if(i!=j && k!=i && k!=j && tu[i][k]!=0 && tu[k][j]!=0){
						if(tu[i][j]==0)tu[i][j]=tu[i][k]+tu[k][j];
						else tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]);
					}
				}	
			}
		}
		for(int i = 1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			int ans=INT_MAX;
			vector<int>jin;
			vector<int>chu;
			for(int i = 1;i<=n;i++){
				if(xian[i][l]!=0)jin.push_back(i);
				
				if(xian[i][r]!=0)chu.push_back(i);
				
			}
			for(int i = 0;i<jin.size();i++){
				for(int j = 0;j<chu.size();j++){
					ans=min(ans,xian[jin[i]][l]+xian[chu[j]][r]+tu[jin[i]][chu[j]]+w[l]+w[r]);
				}
			}
			cout<<ans<<"\n";
		}
		
	}
	else if(9<=c && c<=11){
		for(int i = 1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				for(int k1=0;k1<v[i].size();k1++){
					for(int k2=0;k2<v[j].size();k2++){
						if(v[i][k1].a==v[j][k2].a){
							if(tu[i][j]==0){
								tu[i][j]=v[i][k1].t+v[j][k2].t;
								tu[j][i]=v[i][k1].t+v[j][k2].t;
							}
							else {
								tu[i][j]=min(tu[i][j],v[i][k1].t+v[j][k2].t);
								tu[j][i]=min(tu[j][i],v[i][k1].t+v[j][k2].t);
							}
						}
						
					}
				}
				
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(tu[i][j]!=0){
					dij[i][0].push_back(j);
					dij[i][1].push_back(tu[i][j]);
					dij[j][0].push_back(i);
					dij[j][1].push_back(tu[i][j]);
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)dis[j]=INT_MAX;
			dsl(i);
			for(int j = 1;j<=n;j++)tu[i][j]=dis[j];
		}
		for(int i = 1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			int ans=INT_MAX;
			vector<int>jin;
			vector<int>chu;
			for(int i = 1;i<=n;i++){
				if(xian[i][l]!=0)jin.push_back(i);
				
				if(xian[i][r]!=0)chu.push_back(i);
				
			}
			for(int i = 0;i<jin.size();i++){
				for(int j = 0;j<chu.size();j++){
					ans=min(ans,xian[jin[i]][l]+xian[chu[j]][r]+tu[jin[i]][chu[j]]+w[l]+w[r]);
				}
			}
			cout<<ans<<"\n";
		}
		
		
		
		
		
		
		
	}
	else if(12<=c && c<=19){
		for(int i = 1;i<=m;i++){
			for(int j = 0;j<fd[i].size();j++){
				for(int k = 0;k<fd[i].size();k++){
					if(j==k)continue;
					tu[fd[i][j]][fd[i][k]]=2*T;
					tu[fd[i][k]][fd[i][j]]=2*T;
				}
			}
		}
		
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(tu[i][j]!=0){
					dij[i][0].push_back(j);
					dij[i][1].push_back(2*T);
					dij[j][0].push_back(i);
					dij[j][1].push_back(2*T);
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)dis[j]=INT_MAX;
			dsl(i);
			for(int j = 1;j<=n;j++)tu[i][j]=dis[j];
		}
		for(int i = 1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			int ans=INT_MAX;
			vector<int>jin;
			vector<int>chu;
			for(int i = 1;i<=n;i++){
				if(xian[i][l]!=0)jin.push_back(i);
				
				if(xian[i][r]!=0)chu.push_back(i);
				
			}
			for(int i = 0;i<jin.size();i++){
				for(int j = 0;j<chu.size();j++){
					ans=min(ans,xian[jin[i]][l]+xian[chu[j]][r]+tu[jin[i]][chu[j]]+w[l]+w[r]);
				}
			}
			cout<<ans<<"\n";
		}
		
		
		
	}
		
		
	return 0;
} 
