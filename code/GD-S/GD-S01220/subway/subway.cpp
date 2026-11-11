#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k[502],T,x,y,c,d,w[500005],bj[501],a[502][21],t[502][21],ans;
bool pd[502];
struct edge{
	int x,y;
};
vector<edge>v[502],vt[500005];
struct tt{
	int x,ti;//ti时间 
	bool t,z;//t是否在大厅,z是否在站台 
	int xl;
	bool shang;//上次是在站厅 
};
priority_queue<tt>q;
bool operator < (tt x,tt y){
	return x.ti<y.ti;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	//n地铁线数，m地铁站数，d每个地铁站最多被几条线路经过
	//出行计划数 T
	for(int i=1;i<=m;i++){
		cin>>w[i];//w  i地铁口到站厅所需的时间
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//进过k[i]个地铁站 
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];//地铁站a[i][j]到站台的时间t[i][j] 
//			v[i].push_back({a[i][j],t[i][j],1});
			v[a[i][j]].push_back({i,t[i][j]});
			for(int k=1;k<j;k++){
				vt[a[i][j]].push_back({a[i][k],i});
				vt[a[i][k]].push_back({a[i][j],i});//vt 可通过i地铁线免时间到达的地方 
			}
		}
	}
//	for(int i=1;i<=T;i++){
//		cin>>x[i]>>y[i];
//	}
	while(T--){
		cin>>x>>y;//从x到y
		if(x==y){
			cout<<0<<"\n";
			continue;
		}
		ans=w[x]+w[y];
		while(!q.empty())q.pop();
		q.push({x,0,1,0,0});
		for(int i=1;i<=m;i++)pd[i]=0;
		while(!q.empty()){
			tt u=q.top();
			q.pop();
			if(u.x==y&&u.t==1){
				ans+=u.ti;
				break;
			}
			if(u.t==1){
				for(edge r:v[u.x]){
					if(!pd[r.x]){
						q.push({u.x,u.ti+r.y,0,1,r.x,1});
					}
				}
			}if(u.z==1){
				if(u.shang==1){
					if(pd[u.xl])continue;
					pd[u.xl]=1;
					for(edge r:vt[u.x]){
						q.push({r.x,u.ti,0,1,u.xl,0});
					}
				}
				else{
					for(edge r:v[u.x]){
						if(r.x==u.xl){
							q.push({u.x,u.ti+r.y,1,0,0,0});
						}
					}
				}
			}
		}cout<<ans<<'\n';
	}
}
