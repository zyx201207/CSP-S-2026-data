#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,w;
	bool operator <(const node &x) const{
		return w<x.w;
	} 
};
int k[510],w[500010],ans[1010][1010],c,n,m,d,q,dis[500010],flag[500010],t[50][50],x[50][50],mj[50][50];
vector <node>v[500010];
void dji(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(flag,0,sizeof(flag));
	priority_queue <node> q;
	dis[st]=0;
	flag[st]=1;
	q.push({st,0});
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(int i=0;i<v[now.to].size();i++){
			int neww=v[now.to][i].to;
			
			if(!flag[neww]){
				if(dis[neww]>dis[now.to]+v[now.to][i].w){
					dis[neww]=dis[now.to]+v[now.to][i].w;
				}
				q.push({neww,dis[neww]});
				flag[neww]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[st][i]=ans[i][st]=dis[i];
	}
}int calc(int x,int y){
	return x*50+y;
}
void djii(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(flag,0,sizeof(flag));
	priority_queue <node> q;
	dis[st]=0;
	flag[st]=1;
	q.push({st,0});
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(int i=0;i<v[now.to].size();i++){
			int neww=v[now.to][i].to;	
			if(dis[neww]>dis[now.to]+v[now.to][i].w){
				dis[neww]=dis[now.to]+v[now.to][i].w;
				if(!flag[neww]){
					q.push({neww,dis[neww]});
					flag[neww]=1;
				}
			}
		}
	}
	for(int i=1;i<=calc(m,n);i++){
		ans[st][i]=ans[i][st]=dis[i];
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		for(int i=1;i<=m;i++){
			int x,y,s1,s2;
			cin>>k[i]>>x>>s1>>y>>s2;
			v[x].push_back({y,s1+s2});
			v[y].push_back({x,s1+s2});
		}
		for(int i=1;i<=n;i++){
			dji(i);
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+ans[x][y]<<"\n";
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		for(int i=1;i<=m;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>x[i][j]>>t[i][j];
				mj[i][x[i][j]]=t[i][j];
				if(j>1){
					v[calc(i,x[i][j])].push_back({calc(i,x[i][j-1]),0});
					v[calc(i,x[i][j-1])].push_back({calc(i,x[i][j]),0});
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				for(int u=1;u<=k[i];u++){
					for(int g=1;g<=k[j];g++){
						if(x[i][u]==x[j][g]){
							v[calc(i,x[i][u])].push_back({calc(j,x[j][g]),t[i][u]+t[j][g]});
							v[calc(j,x[j][g])].push_back({calc(i,x[i][u]),t[i][u]+t[j][g]});
						}
					}
				}
			}
		}
		for(int i=1;i<=calc(m,n);i++){
			djii(i);
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			int cnt=INT_MAX;			
			for(int u=1;u<=m;u++){
				for(int g=1;g<=m;g++){
					cnt=min(cnt,ans[calc(u,x)][calc(g,y)]+w[x]+w[y]+mj[u][x]+mj[g][y]);
				}
			}
			cout<<cnt<<"\n";
		}
	}
	
	return 0;
}
