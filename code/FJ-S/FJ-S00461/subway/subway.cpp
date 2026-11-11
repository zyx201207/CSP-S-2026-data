#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,T;
int w[500005];
int k[505];
int a[505][50005],t[505][50005],id[50005][505];
vector<pair<int,int>> e[20005];
int ans1[1005][20005];
bool vis[20005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=m;
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			id[a[i][j]][i]=++cnt;
//			cout<<"**"<<id[a[i][j]][i]<<'\n';
			
		}
	}
//	cout<<"**";
//	if(c<=11){
//		cout<<cnt;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=k[i];j++){
				
				e[id[a[i][j-1]][i]].push_back({id[a[i][j]][i],0});
				e[id[a[i][j]][i]].push_back({id[a[i][j-1]][i],0});
//				cout<<"make:"<<id[a[i][j]][i]<<"->"<<id[a[i][j-1]][i]<<"\n";
				
			}
			for(int j=1;j<=k[i];j++){
				e[id[a[i][j]][i]].push_back({a[i][j],t[i][j]});
				e[a[i][j]].push_back({id[a[i][j]][i],t[i][j]});
//				cout<<"make:"<<a[i][j]<<"->"<<id[a[i][j]][i]<<"\n";
			}
			
			
		}
		memset(ans1,0x3f,sizeof ans1);
		for(int i=1;i<=m;i++){
			memset(vis,0,sizeof vis);
			priority_queue<pair<int,int>> q;
			q.push({0,i});
			ans1[i][i]=0;
			while(q.size()){
				int u=q.top().second;
				q.pop();
				if(vis[u]){
					continue;
				}
				vis[u]=1;
				for(auto it:e[u]){
//					cout<<"&&"<<u<<" "<<ans1[i][it.first]<<'\n';
					if(ans1[i][it.first]>ans1[i][u]+it.second){
						
						ans1[i][it.first]=ans1[i][u]+it.second;
						q.push({-ans1[i][it.first],it.first});
					}
				}
			}
		}
		for(int i=1;i<=T;i++){
			int x,y;
			cin>>x>>y;
			cout<<ans1[x][y]+w[x]+w[y]<<'\n';
		}
		return 0;
//	}
//	if(c>=12&&c<=19){
//		
//	}
	
	return 0;
}

