#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500010];
vector<pair<int,int> >l[500010];
int dis[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(dis,0x3f,sizeof dis);
	//cout<<"!";
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	c=91917878114514;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//cout<<"Q";
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			pair<int,int>p;
			p.first=i;
			p.second=t;
			l[a].push_back(p);
		}
	}
	//cout<<"A";
	for(int i=1;i<=m;i++){
		//cout<<"W";
		if(l[i].size()<=1)continue;
		for(int j=0;j<l[i].size();j++){
			for(int k=0;k<l[i].size();k++){
				//cout<<"F";
				int u=l[i][j].first,t1=l[i][j].second,v=l[i][k].first,t2=l[i][k].second;
				//cout<<u<<" "<<v<<" "<<t1<<" "<<t2<<endl;
				//cout<<"U";
				dis[u][v]=min(dis[u][v],t1+t2);
				//cout<<"C";
				dis[v][u]=dis[u][v];
				//cout<<"K";
			}
		}
	}
	//cout<<"B";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" "; 
//		}cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" "; 
//		}cout<<endl;
//	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	//cout<<"c";
	while(p--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<l[x].size();i++){
			for(int j=0;j<l[y].size();j++){
				ans=min(ans,dis[l[x][i].first][l[y][j].first]+l[x][i].second+l[y][j].second); 
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
