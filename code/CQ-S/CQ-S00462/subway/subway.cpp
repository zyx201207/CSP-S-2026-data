#include<bits/stdc++.h>
#define N 505
#define M 500005
using namespace std;
int c,n,m,d,q,k[N],cnt,vis[M+N];
long long dis[M+N],w[M],ans[M],vi[M][20];
struct A{
	int x,y;
};
struct B{
	int x,y,id;
}qq[M];
vector<A> v[M+N];
priority_queue<pair<int,int>> p;
long long solve(int s,int t){
	for(int i=1;i<=cnt;i++) dis[i]=-1;
	dis[s]=0;
	p.push({dis[s],s});
	while(!p.empty()){
		int d=p.top().first,x=p.top().second;p.pop();
		if(vis[x]) continue;
		for(auto i:v[x]){
			int nd=dis[x]+i.y;
			if(dis[i.x]==-1||dis[i.x]>nd){
				dis[i.x]=nd;
				p.push({dis[i.x],i.x});
			}
		} 
	}
	if(t>0) return dis[t];
	return 0;
}
bool cmp(B x,B y){
	return x.x<y.x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c==20||c==21){
		long long mi=-1;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int x,y;
				cin>>x>>y;
				vi[x][i]=y;
			}
		}
		for(int i=1;i<=m;i++){
			if(vi[i][1]&&vi[i][2]){
				if(mi==-1) mi=vi[i][1]+vi[i][2];
				mi=min(mi,vi[i][1]+vi[i][2]);
			}
		}
		for(int i=1;i<=q;i++){
			int x,y,ans=0;
			cin>>x>>y;
			ans+=w[x]+w[y];
			if(vi[x][1]&&vi[y][1]&&vi[x][2]&&vi[y][2]){
				cout<<min(vi[x][1]+vi[y][1],vi[x][2]+vi[y][2])+ans<<"\n";
			}
			else if(vi[x][1]&&vi[y][1]){
				cout<<vi[x][1]+vi[y][1]+ans<<"\n";
			}
			else if(vi[x][2]&&vi[y][2]){
				cout<<vi[x][2]+vi[y][2]+ans<<"\n";
			}
			else if(vi[x][1]&&vi[y][2]){
				cout<<vi[x][1]+mi+vi[y][2]+ans<<"\n";
			}
			else if(vi[x][2]&&vi[y][1]){
				cout<<vi[x][2]+mi+vi[y][1]+ans<<"\n";
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i+m,y});
			v[i+m].push_back({x,y});
		}
	}
	cnt=n+m;
	for(int i=1;i<=q;i++){
		int x,y,ans=0;
		cin>>x>>y;
		if(x>y) swap(x,y);
		qq[i]={x,y,i};
	}
	if(q<cnt){
		for(int i=1;i<=q;i++){
			int x=qq[i].x,y=qq[i].y;
			cout<<w[x]+w[y]+solve(x,y)<<"\n";
		}	
	}
	else{
		sort(qq+1,qq+1+q,cmp);
		for(int i=1,j=1;i<=q;){
			while(j<qq[i].x&&j<=n) j++;
			solve(j,-1);
			while(qq[i].x==j){
;				ans[qq[i].id]=dis[qq[i].y]+w[qq[i].x]+w[qq[i].y];
				i++;
			}
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	}
	return 0;
}/*
好想玩原神 
*/
