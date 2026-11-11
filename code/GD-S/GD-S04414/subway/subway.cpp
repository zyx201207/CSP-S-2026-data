#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=510;
int w[N];

int c,n,m,dd,q;

struct node{
	ll d;
	int x,y;
	
	bool operator < (const node& oth)const{
		return d>oth.d;//?
	}
};
vector <node> adj[N][25];//第几结点分站到第几结点 
int len[N],tim[N][25];//各地铁站分站数 

ll dis[N][25];
void dijkstra(int st,int ed){
	priority_queue <node> pq;
	
	for (int i=0;i<=m;i++){
		for (int j=0;j<=20;j++)dis[i][j]=1e18;
	}
	
	
	pq.push({0,st,0});
	dis[st][0]=0;

	
	while (!pq.empty()){
		
		
		
		ll d=pq.top().d;
		int x=pq.top().x,y=pq.top().y;
		
//		cout <<d<<' '<<x<<' '<<y<<'\n';
		
		
		pq.pop();
		
		if (dis[x][y]<d)continue;
		
		for (node e:adj[x][y]){
			int ex=e.x,ey=e.y;
			ll ed=e.d;
			
//			cout <<ed<<' '<<ex<<' '<<ey<<endl;
			
			if (dis[ex][ey]>dis[x][y]+ed){
				dis[ex][ey]=dis[x][y]+ed;
				pq.push({dis[ex][ey],ex,ey});
			} 
		}
		
//		cout <<endl;
	}
	
	cout <<dis[ed][0]<<'\n';
	
}





int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
//	cout <<-81094;
	cin >>c>>n>>m>>dd>>q;
	
	for (int i=1;i<=m;i++)cin >>w[i];
	
	for (int i=1;i<=n;i++){
		
		
		int k;
		cin >>k;
		int lsta,lstlen;
		for (int j=1;j<=k;j++){
			int a,t;
			cin >>a>>t;
			
			len[a]++;
			lstlen=len[a];
			
			tim[a][len[a]]=t;
			
			if (j!=1){
				adj[a][len[a]].push_back({0,lsta,lstlen});
				adj[lsta][lstlen].push_back({0,a,len[a]});
				
				
//				if (lsta==2&&lstlen==1)cout <<a<<' '<<len[a]<<endl;
				
//				if (lsta==3&&lstlen==1||a==3&&len[a]==1)cout <<a<<' '<<t<<endl;
				
//				cout <<a<<' '<<len[a]<<'\n';
//				cout <<lsta<<' '<<lstlen<<'\n'<<endl;
			}
			
			lsta=a;
			lstlen=len[a];
//			if (len[2]==2)cout <<a<<' '<<t<<endl;
		}
//		cout <<endl;
	}
	
	
	
//	for (int i=1;i<=m;i++){
//		
//		for (int j=1;j<=2;j++){
//			
//			cout <<i<<' '<<j<<endl;
//			
//			for (node e:adj[i][j]){
//			int ex=e.x,ey=e.y;
//			ll ed=e.d;
//			
//			cout <<ed<<' '<<ex<<' '<<ey<<endl;
//			
//			
//		}
//		cout <<endl<<endl;
//			
//		}
//		
//		cout <<endl<<endl<<endl;
//	}
	
	
	for (int i=1;i<=m;i++){
		for (int j=0;j<=len[i];j++){
			for (int k=0;k<=len[i];k++){
				if (j!=k){
					adj[i][j].push_back({tim[i][j]+tim[i][k],i,k});
				}
			}
		}
	}
	
	for (int i=1;i<=q;i++){
		int x,y;
		cin >>x>>y;
		
//		cout <<1;
		
		dijkstra(x,y);
	}
	
	return 0;
}
