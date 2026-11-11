#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,w[100005],k[100005],t[505][50005],n,m,d,q,dis[50005][505];
vector<int>vec2[100005],vec3[100005];
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dis[j][i]=1e18;
		}
	}
	q.push({0,s});
	for(int i:vec2[s]){
		dis[s][i]=t[i][s];
	}
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		for(int s1:vec2[x]){
			for(int i:vec3[s1]){
				if(dis[x][s1]<dis[i][s1]){
					dis[i][s1]=dis[x][s1];
					q.push({dis[i][s1],i});
				}
			}
		}
		for(int s1:vec2[x]){
			for(int s2:vec2[x]){
				if(dis[x][s1]+t[s1][x]+t[s2][x]<dis[x][s2]){
					dis[x][s2]=dis[x][s1]+t[s1][x]+t[s2][x];
					q.push({dis[x][s2],x});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x;
			cin>>t[i][x];
			vec2[x].push_back(i);
			vec3[i].push_back(x);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		int minn=1e18;
		for(int i:vec2[y]){
			minn=min(minn,w[x]+w[y]+dis[y][i]+t[i][y]);
		}
		cout<<minn<<endl;
	}
	return 0;
}
