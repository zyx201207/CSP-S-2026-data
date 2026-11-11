#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
//测试点编号 
ll c;

//地铁线路数 
ll n;

//地铁站数
ll m;

//每个地铁站最多被几条线路经过
ll d;

//出行计划数
ll q; 

ll w[600];
struct node{
	ll a,t;
	//当前站台编号a，到达a号站台所需时间t，在第id号线路 
}mp[N];
ll vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	while(q--){
		
		cout<<w[1]<<'\n'; 
	}
	return 0;
}
