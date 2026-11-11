#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+10,M=1e3+10,INF=0x3f3f3f3f;
int c,n,m,d,q,x,y,ans;
int w[M],k,a,t[N][M];
bool vis[N];
int dis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1; 
void dj(int x){
	while(!q1.empty()) q1.pop();
	memset(dis,INF,sizeof(dis));
	memset(vis, 0 ,sizeof(vis));
	dis[x]=0;
	q1.push({dis[x],x});
	while(!q1.empty()){
		int x=q1.top().second,w=q1.top().first;
		q1.pop();
		if(vis[x])break; vis[x]=1;
		for(int k=1;k<=n;k++){ 						//第k条地铁上 
			if(t[k][x]==INF) continue; 				//跟新最小路
			for(int i=1;i<=m;i++){ 					//拜访k条地铁上可以道德地点 
				if(vis[i]||t[k][i]==INF) continue; 	//只是下车到站台不上去 
				if(dis[i]>w+t[k][x]+t[k][i]){
					dis[i]=w+t[k][x]+t[k][i];
					q1.push({dis[i],i});
				}
			} 
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(t,INF,sizeof(t));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t[i][a];
		}
	}
	while(q--){
		cin>>x>>y;
		if(x==y){ cout<<"0\n"; continue; }
		dj(x);
		ans=w[x]+w[y]+dis[y];
		cout<<ans<<endl;
	}
}
//我要打cs team spirit up; 
