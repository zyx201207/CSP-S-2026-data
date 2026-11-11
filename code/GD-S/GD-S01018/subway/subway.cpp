#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
const int M=5e5;
const int N=505;
int w[M];
//vector<pair<int,int>>a[N];//存线路连站点 
vector<pair<int,int>>a[M+N];//存站点连线路 
int c,n,m,d,q;
void solve(){
	int x,y;
	cin>>x>>y;
	vector<int>vis(M+N,1e9);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
	//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
	q1.push({0,x});
	while(!q1.empty()){
		auto nw=q1.top();
		q1.pop();
		int na=nw.second;
		int nt=nw.first;
		if(vis[na]<=nt)continue;
		vis[na]=nt;
		for(auto tw:a[na]){
			int ta=tw.first;
			int tt=tw.second;
			q1.push({nt+tt,ta});
		}
	}
	cout<<w[x]+w[y]+vis[y]<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i+M].push_back({x,y});
			a[x].push_back({i+M,y});
		}
	}
	
	for(int i=1;i<=q;i++){
		solve();
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
