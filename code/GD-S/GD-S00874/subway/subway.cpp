#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
vector<pair<int,int> > v[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	if(c>=9 && c<=11){
		long long dis[505][505];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++) dis[i][j]=(i==j?0:1e18);
		}for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			int a1,t1,a2,t2;
			cin>>a1>>t1>>a2>>t2;
			dis[a1][a2]=1ll*t1+t2,dis[a2][a1]=1ll*t1+t2;
		}for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(dis[i][k]!=1e18 && dis[k][j]!=1e18) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}while(q--){
			int s,t;
			cin>>s>>t;
			printf("%lld\n",dis[s][t]+w[s]+w[t]);
		}
	}else if(c>=12 && c<=19){
		map<pair<int,int>,long long> mp;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int a,t;
				cin>>a>>t;
				v[i+m].push_back({a,t});
				v[a].push_back({i+m,t});
			}	
		}while(q--){
			int si,ti;
			cin>>si>>ti;
			if(mp[{si,ti}]){
				scanf("%lld\n",mp[{si,ti}]);
				continue;
			}bool vis[40005];
			for(int i=1;i<=2*m;i++) vis[i]=0;
			deque<pair<int,long long> > dq;
			dq.push_back({si,0});
			while(!dq.empty()){
				pair<int,long long> t=dq.front();
				dq.pop_front();
				if(t.first==ti){
					printf("%lld\n",t.second+w[si]+w[ti]);
					mp[{si,ti}]=t.second+w[si]+w[ti];
					break;
				}for(int i=0;i<v[t.first].size();i++){
					if(v[t.first][i].first>m && !vis[v[t.first][i].first]) dq.push_front({v[t.first][i].first,t.second+v[t.first][i].second}),vis[v[t.first][i].first]=1;
					else if(!vis[v[t.first][i].first]) dq.push_back({v[t.first][i].first,t.second+v[t.first][i].second}),vis[v[t.first][i].first]=1;
				}
			}
		}
	}else{
		long long dis[605][605];
		for(int i=1;i<=2*m;i++){
			for(int j=1;j<=2*m;j++) dis[i][j]=(i==j?0:1e18);
		}for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				int a,t;
				cin>>a>>t;
				dis[a][i+m]=t,dis[i+m][a]=t;
			}
		}for(int k=1;k<=2*m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(dis[i][k]!=1e18 && dis[k][j]!=1e18) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}while(q--){
			int s,t;
			cin>>s>>t;
			printf("%lld\n",dis[s][t]+w[s]+w[t]);
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
