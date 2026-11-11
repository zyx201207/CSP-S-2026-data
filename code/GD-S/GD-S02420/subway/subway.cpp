#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//贪心 
const int maxm=5e5+10;
ll c,n,m,d,q,x,y;
ll w[maxm];
struct node{
	ll num,t;
};
vector<node> vec[maxm];//vec[站]={经过线路,站厅走到第i条线路的站台的时间}
vector<ll> vec2[505];//记录每一条线的站台 
ll f[1005][1005];//i->j最短用时
ll num1;
bool check(ll u,ll v){//是否在同一条地铁线 
	for(int i=0;i<vec[u].size();i++){
		for(int j=0;j<vec[v].size();j++){
			ll numu=vec[u][i].num,numv=vec[v][j].num;
			if(numu==numv){
				num1=numu;
				return true;
			}
		}
	}
	return false;
}
void solve2(){
	 for(int i=1;i<=m;i++){
	 	for(int j=1;j<=m;j++){
	 		for(int k=1;k<=m;k++){
	 			ll s1=0,s2=0;
	 			if(check(i,j)){
	 				bool pd=false;
	 				for(int p=0;p<vec2[num1].size();p++){
	 					int u=vec2[num1][p];
	 					if((u==i||u==j)&&!pd){
	 						pd=true;
						}
					}
				}
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	ll k,a1,t1;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a1>>t1;
			vec[a1].push_back({i,t1});
			vec2[i].push_back(a1); 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(check(x,y)){
			ll ans=w[x]+w[y];
			for(int i=0;i<vec[x].size();i++){
				if(vec[x][i].num==num1){
					ans+=vec[x][i].t;
					break;
				}
			}
			for(int i=0;i<vec[y].size();i++){
				if(vec[y][i].num==num1){
					ans+=vec[y][i].t;
					break;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
