#include<bits/stdc++.h>
using namespace std;
struct acd{
	int num,time;
};
struct node{
	int x,step;
};
struct ace{
	int x,y,t;
};
acd a[505][50005];
bool bb[505][500005];
int b[500005];
int d[500005];
int c,n,m,dd,r;
vector<node> v[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>dd>>r;
	for(int k=1;k<=m;k++)cin>>b[k];
	for(int k=1;k<=n;k++){
		cin>>d[k];
		for(int i=1;i<=d[k];i++){
			cin>>a[k][i].num>>a[k][i].time;
			v[a[k][i].num].push_back({i,a[k][i].time});
		}
	}
	int cnt=0;
	while(r--){
		int cnt=1e9;
		queue<ace> q;
		memset(bb,0,sizeof(bb));
		int x,y;
		cin>>x>>y;
		for(int k=0;k<v[x].size();k++){
			int aa=v[x][k].x;//线路 
			q.push({aa,x,v[x][k].step});
			bb[aa][x]=true;
		}
		while(q.size()){
			auto h=q.front();//x线路   y地铁站    t时间 
			q.pop();
			if(h.y==y){
				cout<<h.t+b[x]+b[y]<<"\n";
				break;
			}
		//	bool aa=false;
			for(int k=1;k<=d[h.x];k++){
				int v1=a[h.x][k].num;
				if(bb[h.x][v1]==false){
					bb[h.x][v1]=true;
					if(v1!=y)q.push({h.x,v1,h.t});
					else{
						q.push({h.x,v1,h.t+a[h.x][v1].time});
//						cout<<h.t+b[x]+b[y]+a[h.x][v1].time<<"\n";
//						aa=true;
//						break;
					}
				}
			}
		//	if(aa==true)break;
			for(int k=0;k<v[h.y].size();k++){
				auto v1=v[h.y][k];
				if(bb[v1.x][h.y]==false){
					bb[v1.x][h.y]==true;
					q.push({v1.x,h.y,h.t+v1.step});//+a[h.x][h.y].time
				}
			}
		}
	}
	return 0;
} 
