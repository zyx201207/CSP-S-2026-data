#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
int n,d,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int h=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			vector<pair<int,int> >v[5005];
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						v[i].push_back({1,j});
					}
				} 
			}
			int ans;
			int dis[5005]={};
			bool vis[5005]={};
			priority_queue<pii,vector<pii>,greater<pii> >q;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					ans=0;
					memset(dis,0x3f,sizeof(dis));
					memset(vis,0,sizeof(vis));
					q.push({0,i});
					dis[i]=0;
					while(!q.empty()){
						int x=q.top().second;
						if(x==j)break;
						q.pop();
						if(vis[x])continue;
						vis[x]=1;
						for(auto k:v[x]){
							int d=k.first,y=k.second;
							if(dis[y]>=dis[x]+d){
								dis[y]=dis[x]+d;
								q.push({dis[y],y});
							}
						}
					}
					while(!q.empty()){
						int d=q.top().first,y=q.top().second;
						q.pop();
						if(y==j&&dis[j]==d)ans++;
					}
					if(ans==2)h++;
				}
			}
			cout<<h<<endl;
		}
	}else{
		while(t--){
			cout<<0<<endl;
		}
	}
	return 0;
}
