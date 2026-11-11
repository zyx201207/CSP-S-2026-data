#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,q,a[500010],b[500010],x,y,jl[550][550],u_,v_;
vector<long long>d[500010];
vector<pair<long long,long long> >c[500010],e[500010];/*
struct ans{long long s,t,sum;}_;
ans f(long long st,long long end_){
	
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(jl,0x3f,sizeof(jl));
	cin>>t>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=0;j<b[i];j++){
			cin>>x;
			c[i].push_back({x,j});
			e[x].push_back({i,j});
			cin>>x;
			d[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		if(e[i].size()==1)continue;
		for(int u=0;u<e[i].size()-1;u++){
			for(int v=u+1;v<e[i].size();v++){
				u_=e[i][u].first,v_=e[i][v].first;
				jl[u_][v_]=jl[v_][u_]=min(jl[u_][v_],d[u_][e[i][u].second]+d[v_][e[i][v].second]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		//_=f(x,y);
		//cout<<a[x]+a[y]+d[_.s][c[x].second]+d[_.t][c[y].second]+_.sum<<'\n';
		if(e[x].size()==1&&e[y].size()==1&&e[x][0].first!=e[y][0].first){
			cout<<a[x]+a[y]+d[e[x][0].first][e[x][0].second]+d[e[y][0].first][e[y][0].second]+jl[1][2]<<'\n';
		}
		else if(e[x].size()<e[y].size()){
			cout<<a[x]+a[y]+d[e[x][0].first][e[x][0].second]+d[e[x][0].first][e[y][0].second]<<'\n';
		}
		else if(e[y].size()<e[x].size()){
			cout<<a[x]+a[y]+d[e[y][0].first][e[x][0].second]+d[e[y][0].first][e[y][0].second]<<'\n';
		}
		else{
			if(e[y][0].first==1)swap(e[y][0],e[y][1]);
			cout<<a[x]+a[y]+min({d[0][e[x][0].second]+d[0][e[y][0].second],d[1][e[x][1].second]+d[1][e[y][1].second],d[0][e[x][0].second]+d[1][e[y][1].second]+jl[0][1],d[0][e[y][0].second]+d[1][e[x][1].second]+jl[0][1]})<<'\n';
		}
	}
	return 0;
}
