#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=5e3+10; 
int cn,n,m,d,q;
int w[N],t[510][N];
int ml[510][510];
vector<int>v[N],bi[510],a[510];
bool vis[510];
void dij(int x){
	memset(vis,sizeof(vis),0);
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(make_pair(0,x));
	ml[x][x]=0;
	while(!q.empty()){
		int xx=q.top().first,yy=q.top().second;
		q.pop();
		if(vis[yy])continue;
		ml[x][yy]=xx;
		vis[yy]=1;
		for(int i=1;i<=bi[yy].size();i++){ 
			q.push(make_pair(xx+ml[yy][bi[yy][i]],bi[yy][i]));
			if(ml[x][bi[yy][i]]>xx+ml[yy][bi[yy][i]]){
				ml[x][bi[yy][i]]=xx+ml[yy][bi[yy][i]];
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cn>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;cin>>x;
			a[i].push_back(x);
			v[x].push_back(i);
			cin>>t[i][x];
		}
	}
	for(int i=0;i<505;i++){
		for(int j=0;j<505;j++)ml[i][j]=1e9;
	}
	for(int i=1;i<=m;i++){
		cout<<v[i].size()<<" ";
		for(int j=1;j<=v[i].size();j++){
			for(int k=j+1;k<=v[i].size();k++){
				int xx=v[i][j],yy=v[i][k];
				ml[xx][yy]=min(ml[xx][yy],t[xx][i]+t[yy][i]);
				ml[yy][xx]=ml[xx][yy];
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		int x,y,ans=1e9;
		cin>>x>>y;
		for(int i=1;i<=v[x].size();i++){
			for(int j=1;j<=v[y].size();j++){
				ans=min(ans,t[v[x][i]][x]+ml[v[x][i]][v[y][j]]+t[v[y][j]][y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
