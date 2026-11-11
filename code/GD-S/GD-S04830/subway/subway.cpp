#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,w[500005],dis[1005][2005],vis[2005],c,d,qq,len,i,j,s,t,k,ans;
struct dui{
	long long x,len;
	bool operator < (dui oth)const{
		return x>oth.x;
	}
}r;
vector<dui> v[2005];
priority_queue<dui> q;
void dij(long long a){
	while(!q.empty())q.pop();
	memset(&vis,0,sizeof(vis));
	for(j=1;j<=n+m;j++)dis[a][j]=1e18;
	dis[a][a]=0;
	q.push({a,0});
	while(!q.empty()){
		if(vis[q.top().x])return ;
		vis[q.top().x]=1;
		r=q.top();
		q.pop();
		for(auto xx:v[r.x]){
			if(dis[a][xx.x]>dis[a][r.x]+xx.len){
				dis[a][xx.x]=dis[a][r.x]+xx.len;
				q.push({xx.x,xx.len});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>a>>len;
			v[i+m].push_back({a,len});
			v[a].push_back({i+m,len});
		}
	}
	for(i=1;i<=m;i++){
		dij(i);
	}
	while(qq--){
		cin>>s>>t;
		cout<<w[s]+w[t]+dis[s][t]<<endl;
	}
	return 0;
}
