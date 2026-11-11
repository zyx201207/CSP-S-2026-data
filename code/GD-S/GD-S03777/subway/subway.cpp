#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=507;
struct node{
	int y,w;
};
vector<node> g[500007];
//struct node{
//	int y,w,num;
//};
//vector<node> g2[307];
struct mode{
	int x,num;
	bool operator<(const mode a)const{
		return num>a.num;
	}
}; 
//struct mode{
//	int x,num;
//	bool operator<(const mode a)const{
//		return num>a.num;
//	}
//}; 
int c,n,m,d,q,x,y,z;
int a[500007],dis[1007][1007];//57,307
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	if(7<=c&&c<=11){
		memset(dis,0x3f3f3f3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			int ww,xx,yy,zz;
			cin>>x>>ww>>xx>>yy>>zz; 
			g[ww].push_back({yy,xx+zz});
			g[yy].push_back({ww,xx+zz});
		}
		for(int i=1;i<=m;i++){
			priority_queue<mode> pq;
			pq.push({i,0});
			dis[i][i]=0;
			while(!pq.empty()){
//				cout<<1;
				mode tp=pq.top();
				int x=tp.x,num=tp.num;
				pq.pop();
				if(dis[i][x]<num) continue;
				for(node k:g[x]){
					int y=k.y,w=k.w;
//					cout<<w<<endl;
					if(dis[i][y]>dis[i][x]+w){
						dis[i][y]=dis[i][x]+w;
//						cout<<dis[i][y]<<' '<<dis[i][x]<<' '<<w<<endl;
						pq.push({y,dis[i][y]});
					}
				}
			}
//			cout<<endl;
		}
		while(q--){
			cin>>x>>y;
			cout<<dis[x][y]+a[x]+a[y]<<endl;
		}
	}
//	if(c<=6){
//		for(int i=1;i<=n;i++){
//			cin>>x;
//			for(int j=1;j<=x;j++){
//				cin>>y>>z;
//				g[i].push_back({y,z,i});
//			}
//		}
//		while(q--){
//			cin>>x>>y;
//			priority_queue<mode2> pq;
//			pq.push({i,0});
//			dis[i][i]=0;
//			while(!pq.empty()){
////				cout<<1;
//				mode tp=pq.top();
//				int x=tp.x,num=tp.num;
//				pq.pop();
//				if(dis[i][x]<num) continue;
//				for(node k:g[x]){
//					int y=k.y,w=k.w;
////					cout<<w<<endl;
//					if(dis[i][y]>dis[i][x]+w){
//						dis[i][y]=dis[i][x]+w;
////						cout<<dis[i][y]<<' '<<dis[i][x]<<' '<<w<<endl;
//						pq.push({y,dis[i][y]});
//					}
//				}
//			}
//			
//		}
//	}
	return 0;
} 
