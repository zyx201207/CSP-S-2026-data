#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,M=5e3+10,inf=INT_MAX;
typedef pair<int,int> pii;
int ww[M];
vector<pii> g[M+N];
int c,n,m,d,q;
int minds[N+M][N+M];
void djstrla(int s){
	for(int i=1;i<=n+m;i++){
		minds[s][i]=inf;
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,s});
	minds[s][s]=0;
	while(!pq.empty()){
		pii cur=pq.top();
		pq.pop();
		int minw=cur.first;
		int minv=cur.second;
		if(minds[s][minv]!=minw) continue;
		for(auto it:g[minv]){
			int w=it.first;
			int v=it.second;
			if(w+minw<minds[s][v]){
				minds[s][v]=minw+w;
				pq.push({minds[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({t,m+i});
			g[m+i].push_back({t,a});
		}
	}
	for(int i=1;i<=m;i++){
		djstrla(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<ww[x]+ww[y]+minds[x][y]<<endl;
	}
	return 0;
}