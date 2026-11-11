#include<bits/stdc++.h>
using namespace std;
const int M=5e6+10;
const int N=5e3+10;
const int INF=0x3f3f3f3f; 
int w[M];
int a[30][M];
int t[30][M];
int vis[M];
int dis[M];
vector<pair<int,int>>yu[M];
void dij(int l,int r){
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));
	priority_queue<int,vector<int>,greater<>>q;
	q.push(l);
	dis[l]=0;
	while(!q.empty()){
		int op=q.top();
		q.pop();
		if(vis[op]){
			if(op==r){
				break;
			}
			continue;
		}
		vis[op]=1;
		for(auto kl:yu[op]){
			int yy=kl.first;
			int ww=kl.second;
			if(dis[yy]>dis[op]+ww){
				dis[yy]=dis[op]+ww;
				q.push(yy);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int  c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
			for(int o=1;o<=k;o++){
			cin>>a[i][o]>>t[i][o];  
			}
		}
		for(int i=1;i<=n;i++){
			for(int o=1;o<=k;o++){
			for(int g=o+1;g<=k;g++){
			yu[a[i][o]].push_back({a[i][g],t[i][o]+t[i][g]});
			}
			}
		}
	int sl,sr;
	for(int i=1;i<=q;i++){
		cin>>sl>>sr;
		dij(sl,sr);
		cout<<dis[sr]+w[sl]+w[sr]<<"\n";
	}
	return 0;
}




