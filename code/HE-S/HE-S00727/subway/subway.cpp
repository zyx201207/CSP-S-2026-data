#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,t[505],x,y,sttp=0;
struct M{
	long long v;
	long long time;
	long long w;
	long long ww;
};
vector<M> a[505];
void dfs(int fa,int faw,int u,int ww,long long step){
	//cout<<step<<":"<<u<<" "<<ww<<endl;
	if(u==y&&ww==0){
		sttp=min(sttp,step);
		return;
	}
	
	for(int i=0;i<a[u].size();i++){
		int v =a[u][i].v;
		int w =a[u][i].w;
		int tt=a[u][i].time;
		if(v==fa&&w==faw){
			continue;
			
		}
		else{
			//cout<<v<<" "<<ww<<" "<<tt<<endl;
			dfs(u,ww,v,w,step+tt);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//地铁口 
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	//路线 
	for(int i=1,k;i<=n;i++){
		cin>>k;
		int u[505],kk[505];
		for(int j=0;j<k;j++){
			cin>>u[j]>>kk[j];
			a[u[j]].push_back({u[j],kk[j],i,0});
			a[u[j]].push_back({u[j],kk[j],0,i});
		}
		for(int j=0;j<k;j++){
			for(int l=0;l<k;l++){
				if(u[l]!=u[j]){
					a[u[j]].push_back({u[l],0,i,i});
				}
			}
		}
	}
	//行程 
	for(int i=0;i<q;i++){
		cin>>x>>y;
		dfs(0,0,x,0,0);
		cout<<t[x]+t[y]+sttp<<endl;
	}
	return 0;
}
