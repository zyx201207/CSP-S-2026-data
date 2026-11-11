#include<iostream>
#include<cstdio> 
#include<cstring>
#include<vector>
#include<queue>
#include<string>
using namespace std;
struct qq{
	int v,w;
};
vector<qq>vv[5005];
vector<qq>f[5005];
int w[5005];
int d[2005][2005]; 
bool b[505][505];
int ch=0x3f3f;
int minn=2e9,y;
void dfs(int x,int sum,int t){
	if(x==y){
		minn=min(minn,sum);
		return ;
	}
	b[t][x]=true;
	for(auto xx:f[x]){
		if(b[xx.v][x]==true){
			continue;
		}
		dfs(x,sum+xx.w,xx.v);
	}
	for(auto xx:vv[t]){
		int xv=xx.v;
		int xw=xx.w;
		if(b[t][xv]==true)continue;
		dfs(xv,sum+xx.w,t);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,e,q;
	cin>>c>>n>>m>>e>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		int _u,_w;
		for(int j=1;j<=k;j++){
			cin>>_u>>_w;
			vv[i].push_back({_u,_w});
			f[_u].push_back({i,_w});
		}
	}
	int x;
	while(q--){
		memset(b,false,sizeof(b));
		cin>>x>>y;
		if(d[x][y]!=0){
			cout<<d[x][y]<<"\n";
			continue;
		}
		for(auto xx:f[x]){
			b[xx.v][x]==true;
			dfs(x,xx.w,xx.v);
		}
		cout<<minn+w[x]+w[y]<<"\n";		
	}
	return 0;
}
