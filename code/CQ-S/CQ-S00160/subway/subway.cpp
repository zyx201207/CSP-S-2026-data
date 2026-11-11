//Could you marry with me,Takanashi Hoshino?
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
int k[505];
vector<int>a[505],t[505];
map<int,int>t_[505];
vector<int>rail[500005];
int trans[505][505];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int dis[505];
vector<pair<int,int>>gra[505];
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto _=pq.top();
		pq.pop();
		int u=_.second,uw=_.first;
		if(dis[u]!=uw)continue;
		for(auto i:gra[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
//int random(){
//	mt19937 mt(0);
//	return ((mt()+mt())*(mt()-mt())%(mt())+mt()-mt())*mt()-mt();
//}
//void randominit_maxlimit(){
//	c=26;
//	n=500;
//	m=500000;
//	d=20;
//	q=100000;
//	for(int i=1;i<=m;i++)w[i]=random()%1000000000;
//	for(int i=1;i<=n;i++){
//		k[i]=20;
//		for(int j=1;j<=k[i];j++){
//			int _a,_t;
//			_a=random()%m+1;
//			_t=random()%1000000000;
//			a[i].push_back(_a);
//			t[i].push_back(_t);
//			t_[i][_a]=_t;
//			rail[_a].push_back(i);
//			int len=rail[_a].size();
//			if(len>=2)
//			gra[rail[_a][len-1]].push_back({rail[_a][len-2],t_[rail[_a][len-1]][_a]+t_[rail[_a][len-2]][_a]}),
//			gra[rail[_a][len-2]].push_back({rail[_a][len-1],t_[rail[_a][len-1]][_a]+t_[rail[_a][len-2]][_a]});
//		}
//	}
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	randominit_maxlimit();//1.018s
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int _a,_t;
			cin>>_a>>_t;
			a[i].push_back(_a);
			t[i].push_back(_t);
			t_[i][_a]=_t;
			rail[_a].push_back(i);
			int len=rail[_a].size();
			if(len>=2)
			gra[rail[_a][len-1]].push_back({rail[_a][len-2],t_[rail[_a][len-1]][_a]+t_[rail[_a][len-2]][_a]}),
			gra[rail[_a][len-2]].push_back({rail[_a][len-1],t_[rail[_a][len-1]][_a]+t_[rail[_a][len-2]][_a]});
		}
	}
//	memset(trans,0x3f,sizeof(trans));
//	for(int i=1;i<=m;i++)
//		for(int j=0;j<rail[i].size();j++)
//			for(int k=j+1;k<rail[i].size();k++)
//				trans[rail[i][j]][rail[i][k]]=trans[rail[i][k]][rail[i][j]]=min(trans[rail[i][j]][rail[i][k]],t_[rail[i][j]][i]+t_[rail[i][k]][i]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<trans[i][j]<<" ";
//		cout<<"\n";
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(trans[i][j]!=0x3f3f3f3f3f3f3f3f){
//				gra[i].push_back({j,trans[i][j]});
//				gra[j].push_back({i,trans[i][j]});
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++)trans[i][j]=trans[j][i]=dis[j];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<trans[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		x=1,y=n;
		int ans=1e18;
		for(int j=0;j<rail[x].size();j++)
			for(int k=0;k<rail[y].size();k++)
				ans=min(ans,t_[rail[x][j]][x]+t_[rail[y][k]][y]+trans[rail[x][j]][rail[y][k]]);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}

/*

*/



