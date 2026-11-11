#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define int long long
#define endl '\n'
#define oo pair<int,int>
const int inf=0x3f3f3f3f3f3f3f3f;
int id,n,m,d,q,w[500005],k[505],ls[20005];
vector<oo> g[500005];
vector<oo> adj[505];
int dis[505];
int dij(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(oo v:adj[u]){
			if(dis[v.first]==inf){
				dis[v.first]=dis[u]+v.second;
				q.push(v.first);
			}
			else dis[v.first]=min(dis[v.first],dis[u]+v.second);
		}
	}
	return dis[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(id>=7&&id<=11){
		if(n==1){
			int minn=inf;
			for(int i=1;i<=n;i++){
				cin>>k[i];
				int a1,t1,a2,t2;
				cin>>a1>>t1;
				if(k[i]==2){
					cin>>a2>>t2;
					minn=min(minn,t1+t2);
				}
			}
			while(q--){
				int x,y,ans;
				cin>>x>>y;
				cout<<"0\n";
			}
			return 0;
		}
		if(n==2){
			int minn=inf;
			for(int i=1;i<=n;i++){
				cin>>k[i];
				int a1,t1,a2,t2;
				cin>>a1>>t1;
				if(k[i]==2){
					cin>>a2>>t2;
					minn=min(minn,t1+t2);
				}
			}
			while(q--){
				int x,y,ans;
				cin>>x>>y;
				if(x==y){
					cout<<"0\n";
					continue;	
				}
				ans=w[x]+w[y];
				ans+=minn;
				cout<<ans<<endl;
			}
			return 0;
		}
		if(n==3){
			int minn=inf,l[4][4];
			for(int i=0;i<4;i++)for(int j=0;j<4;j++)l[4][4]=inf;
			for(int i=1;i<=n;i++){
				cin>>k[i];
				int a1,t1,a2,t2,a3,t3,ls;
				if(k[i]==1)cin>>ls>>ls;
				if(k[i]==2){
					cin>>a1>>t1>>a2>>t2;
					l[a1][a2]=l[a2][a1]=min(l[a1][a2],t1+t2);
				}
				if(k[i]==3){
					cin>>a1>>t1>>a2>>t2>>a3>>t3;
					l[a1][a2]=l[a2][a1]=min(l[a1][a2],t1+t2);
					l[a2][a3]=l[a3][a2]=min(l[a2][a3],t1+t2);
				}
			}
			while(q--){
				int x,y,ans;
				cin>>x>>y;
				if(x==y){
					cout<<"0\n";
					continue;	
				}
				ans=w[x]+w[y];
				ans+=min(l[x][y],l[n-x-y][x]+l[n-x-y][y]);
				cout<<ans<<endl;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			int a1,t1,a2,t2;
			cin>>a1>>t1;
			if(k[i]==2){
				cin>>a2>>t2;
				adj[a1].push_back({a2,t1+t2});
				adj[a2].push_back({a1,t1+t2});
			}
		}
		while(q--){
			int x,y,ans;
			cin>>x>>y;
			if(x==y){
				cout<<"0\n";
				continue;	
			}
			ans=w[x]+w[y];
			ans+=dij(x,y);
			cout<<ans<<endl;
		}
	}
	else if(id==20||id==21){
		if(n==1){
			int minn=inf;
			for(int i=1;i<=n;i++){
				cin>>k[i];
				int a1,t1,a2,t2;
				cin>>a1>>t1;
				if(k[i]==2){
					cin>>a2>>t2;
					minn=min(minn,t1+t2);
				}
			}
			while(q--){
				int x,y,ans;
				cin>>x>>y;
				cout<<"0\n";
			}
			return 0;
		}
		int minn=inf;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			int a1,t1,a2,t2;
			cin>>a1>>t1;
			if(k[i]==2){
				cin>>a2>>t2;
				minn=min(minn,t1+t2);
			}
		}
		while(q--){
			int x,y,ans;
			cin>>x>>y;
			if(x==y){
				cout<<"0\n";
				continue;	
			}
			ans=w[x]+w[y];
			ans+=minn;
			cout<<ans<<endl;
		}
	}
	else if(id>=1&&id<=3){
		if(n==1){
			int minn=inf;
			for(int i=1;i<=n;i++){
				cin>>k[i];
				int a1,t1,a2,t2;
				cin>>a1>>t1;
				if(k[i]==2){
					cin>>a2>>t2;
					minn=min(minn,t1+t2);
				}
			}
			while(q--){
				int x,y,ans;
				cin>>x>>y;
				cout<<"0\n";
			}
			return 0;
		}
		if(n==2){
			int minn=inf;
			for(int i=1;i<=n;i++){
				cin>>k[i];
				int a1,t1,a2,t2;
				cin>>a1>>t1;
				if(k[i]==2){
					cin>>a2>>t2;
					minn=min(minn,t1+t2);
				}
			}
			while(q--){
				int x,y,ans;
				cin>>x>>y;
				if(x==y){
					cout<<"0\n";
					continue;	
				}
				ans=w[x]+w[y];
				ans+=minn;
				cout<<ans<<endl;
			}
			return 0;
		}
		int minn=inf,l[4][4];
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)l[4][4]=inf;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			int a1,t1,a2,t2,a3,t3,ls;
			if(k[i]==1)cin>>ls>>ls;
			if(k[i]==2){
				cin>>a1>>t1>>a2>>t2;
				l[a1][a2]=l[a2][a1]=min(l[a1][a2],t1+t2);
			}
			if(k[i]==3){
				cin>>a1>>t1>>a2>>t2>>a3>>t3;
				l[a1][a2]=l[a2][a1]=min(l[a1][a2],t1+t2);
				l[a2][a3]=l[a3][a2]=min(l[a2][a3],t1+t2);
			}
		}
		while(q--){
			int x,y,ans;
			cin>>x>>y;
			if(x==y){
				cout<<"0\n";
				continue;
			}
			ans=w[x]+w[y];
			ans+=min(l[x][y],l[n-x-y][x]+l[n-x-y][y]);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
